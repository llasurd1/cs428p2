all: server clientx clienty

p1: server.cpp 
	g++ -g server.cpp -o server

p2: clientx
	g++ -g clientx.cpp - clientx
  
p3: clienty
  g++ -g clientt.cpp - clientt
  
clean:
	rm -rf server
	rm -rf clientx
  rm -rf clienty
