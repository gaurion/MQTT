mosquitto_sub -v -u 'gaurav' -P 'Asimov' -t 'myhome/room1/out/1' -p 1885 | xargs -d$'\n' -L1 bash -c 'date "+%Y-%m-%d %T.%3N $0"' >>  /home/bumblebee/Desktop/file.log
