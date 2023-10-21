NUMBER=25000
.PHONY=timer

timer: primec primecpp
	echo 'Timing C'
	./primec ${NUMBER}
	echo -e '\nTiming C++'
	./primecpp ${NUMBER}
	echo '\nTiming Python'
	python3 primes.py

primec: primes.c
	gcc -o $@ $^

primecpp: primes.cpp
	g++ -o $@ $^

clean:
	rm -rf primec primecpp