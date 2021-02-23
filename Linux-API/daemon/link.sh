#!/bin/bash

if [ $UID -ne '0' ]; then
    echo "Must be root"
else
    ln -sf /media/cssouza/SOLIDCRIS/repositories/c_language/08-Linux-API/daemon/sample.service /etc/systemd/system/sample.service
fi