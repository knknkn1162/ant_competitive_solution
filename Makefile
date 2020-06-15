.PHONY: all compile

all: gen compile run

gen:
	test -f $(FILE) || cp -i lib/cpp/base.cpp $(FILE)
compile:
	docker run -it --rm -v $(shell pwd):/home/main -w /home/main gcc:9 /bin/bash -c 'g++ -Wall -Wextra $(FILE) && echo succees'

run:
	docker run -it --rm -v $(shell pwd):/home/main -w /home/main gcc:9 ./a.out