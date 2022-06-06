


echod:
	gcc -o echod server.c

install: echod
	@#@echo -ne $(shell [ $(shell id -u) -eq 0 ] || echo -e "Should be run as root" && exit 1)
	sudo cp echod.service /etc/systemd/system/multi-user.target.wants/
	-sudo killall -9 echod &> /dev/null
	sudo cp echod /usr/local/bin/
	sudo systemctl daemon-reload
	sudo systemctl start echod

