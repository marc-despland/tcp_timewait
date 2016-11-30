#!/bin/bash

git pull
make timewait_server
exec ./timewait_server $@