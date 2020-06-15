# Algoritmo Genético F(x,y) = x^2 -2xy + y^2 <br/>
<br/>
AZUL = mejor individuo <br/>
ROJO = promedio <br/>
en la carpeta fotos se puede ver la primera prueba con una población de 5 individuos y 1000 generaciones<br/>
como se aprecia no converge en una solución óptima.
se aplica una segunda prueba con 1500 generaciones y como se aprecia en el grafico se llega a una solución optima<br/>
se estabiliza el grafico <br/> <br/>
Se modificó la función de aleatorios. <br/>
	antes el rango inicial x = 0-127, y = 0-255 <br/>
	ahora el rango inicial x = 0-30, y = 0-55 <br/>
	Al generar valores aleatorios bajos, se puede lograr ver mejor la convergencia en el gráfico, <br/>
	aunque ahora es necesario más generaciones para llegar a la solución óptima. <br/>
<br/>
se modificó en el operador Selección un error de suma.  <br/>
	en leguaje c++ en el ciclo for del operador selección había un "=" cuando debía ser "+=". <br/>
	por eso había un error con los elementos del promedio en el operador Selección. <br/>
<br/>
finalmente, se mejoro el operador de Mutación <br/>
	antes los bits seleccionados para la mutación en el cromosoma eran casi-fijos. <br/>
	ahora son completamente aleatorios. <br/>



