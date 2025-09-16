#!/bin/bash
# A simple demo script to log the current time

echo "Script executed at: $(date)" >> /tmp/daemon_log.txt


# just to see that it ran in terminal
echo "Hello From The Other Side" >> /dev/pts/0
