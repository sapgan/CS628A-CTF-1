#!/bin/bash

readelf -p .data baby_steps | awk 'NR == 4{ printf("flag is: flag{%s}\n", $3); }'
