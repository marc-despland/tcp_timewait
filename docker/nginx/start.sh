#!/bin/bash

option='1'
if [ "$1" = '2' ] ; then
	option='2';
fi

cp /config/nginx_$option.conf /etc/nginx/nginx.conf
exec /usr/sbin/nginx