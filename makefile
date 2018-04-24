grafica_segundo_orden.pdf: datos.txt grafica.py
	python grafica.py
datos.txt: segunda 
	./segunda > datos.txt
segunda: segunda_derivada.cpp
	c++ segunda_derivada.cpp -o segunda
