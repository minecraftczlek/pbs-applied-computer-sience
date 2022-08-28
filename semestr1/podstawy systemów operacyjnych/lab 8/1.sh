#!/bin/bash
ps -eo pid,user,cmd,%mem,%cpu,time --sort=-time | head -n 11