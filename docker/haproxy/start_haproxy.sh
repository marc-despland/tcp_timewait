#!/bin/bash

option='kal'
if [ "$1" = 'tun' ] ; then
	option='tun';
fi
if [ "$1" = 'pcl' ] ; then
	option='pcl';
fi
if [ "$1" = 'scl' ] ; then
	option='scl';
fi
if [ "$1" = 'fcl' ] ; then
	option='fcl';
fi
cp /config/haproxy_$option.cfg /etc/haproxy/haproxy.cfg
exec /usr/sbin/haproxy -f /etc/haproxy/haproxy.cfg -db