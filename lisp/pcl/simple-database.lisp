;;
;; defile global variable
;;
(defvar *db* nil)
;;
;; make a cd
;;  
(defun make-cd (title artist rating ripped)
  (list :title title :artist artist :rating rating :ripped ripped))
;;
;; add record
;;
(defun add-record (cd)
  (push cd *db*))
;;
;; dump db
;;
(defun dump-db ()
  (dolist (cd *db*)
    (format t "~{~a:~10t~a~%~}~%" cd )))
;;
;; prompt user to input
;;
(defun prompt-read (prompt)
  (format *query-io* "~a: " prompt)
  (force-output *query-io*)
  (read-line *query-io*))
;;
;; prompt user to input CD record
;;
(defun prompt-for-cd ()
  (make-cd
   (prompt-read "Title")
   (prompt-read "Artist")
   (or (parse-integer (prompt-read "Rating") :junk-allowed t) 0)
   (y-or-n-p "Ripped [y/n]: ")))
;;
;; continuous reading CDs
;;
(defun add-cds ()
  (loop (add-record (prompt-for-cd))
     (if (not (y-or-n-p "Another? [y/n]: ")) (return))))
;;
;; save DB to file
;;
(defun save-db (filename)
  (with-open-file (out filename :direction :output :if-exists :supersede)
    (with-standard-io-syntax (print *db* out))))
;;
;; load from file
;;
(defun load-db (filename)
  (with-open-file (in filename)
    (with-standard-io-syntax (setf *db* (read in)))))
;;
;; generalized select function
;;
(defun select (select-fun)
  (remove-if-not select-fun *db*))
;;
;; make comparison expression
;;
(defun make-comparison-expr (field value)
  `(equal (getf cd ,field) ,value))
;;
;; make comparison list
;;
(defun make-comparisons-list (fields)
  (loop while fields
       collecting (make-comparison-expr (pop fields) (pop fields))))
;;
;; generalized selector
;;
(defmacro where (&rest clauses)
  `#'(lambda (cd)
       (and ,@(make-comparisons-list clauses))))
;;
;; update
;;
(defun update (selector-fn &key title artist rating (ripped nil ripped-p))
  (setf *db*
	(mapcar
	 #'(lambda (row)
	     (when (funcall selector-fn row)
	       (if title    (setf (getf row :title)  title))
	       (if artist   (setf (getf row :artist) artist))
	       (if rating   (setf (getf row :rating) rating))
	       (if ripped-p (setf (getf row :ripped) ripped)))
	     row) *db*)))
;;
;; delete
;;
(defun delete-rows (selector-fn)
  (setf *db* (remove-if selector-fn *db*)))