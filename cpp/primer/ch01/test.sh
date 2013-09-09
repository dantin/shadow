#!/bin/bash

Exe_dir=.

$Exe_dir/main_only
$Exe_dir/add < data/add
$Exe_dir/while_count
$Exe_dir/for_count
$Exe_dir/sum < data/sum
$Exe_dir/occurs < data/occurs