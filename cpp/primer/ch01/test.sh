#!/bin/bash

EXE_DIR=.

${EXE_DIR}/main_only
${EXE_DIR}/add < data/add
${EXE_DIR}/while_count
${EXE_DIR}/for_count
${EXE_DIR}/sum < data/sum
${EXE_DIR}/occurs < data/occurs
${EXE_DIR}/item_io < data/item_io
${EXE_DIR}/add_item < data/add_item
${EXE_DIR}/avg_price < data/book_sales