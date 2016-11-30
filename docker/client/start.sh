#!/bin/bash

git pull
make timewait_client
exec ./timewait_client $@