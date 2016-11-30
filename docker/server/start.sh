#!/bin/bash

git pull
make
exec ./timewait_server $@