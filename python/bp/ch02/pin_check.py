#!/usr/bin/env python

database = [
    [ 'albert', '1234' ],
    [ 'dilbert', '4242' ],
    [ 'smith', '7542' ],
    [ 'jones', '9843' ]
]

username = raw_input( 'User name: ' )
password = raw_input( 'PIN code: ' )

if [ username, password ] in database:
    print 'Access granted'
