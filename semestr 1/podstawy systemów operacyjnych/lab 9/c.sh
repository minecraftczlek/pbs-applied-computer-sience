#!/bin/bash
cat /etc/passwd | gawk -F: '!/nologin$/ {print $1}' | sort > zalogowani.txt