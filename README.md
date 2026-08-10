### Introducción

En este proyecto se comparará el comportamiento de C y Python al resolver un problema de búsqueda de raíces.
Para esto se implementarán los métodos de Newton-Raphson y Brent-Dekker, utilizando la función (f(x)=x^3-x-2),
y se ejecutarán bajo las mismas condiciones en ambos lenguajes. La idea es comparar los resultados obtenidos
y principalmente el tiempo de ejecución,para observar de forma práctica las diferencias entre un lenguaje compilado
como C y uno interpretado como Python.

| Lenguaje | Algoritmo | Resultado          |
| -------- | --------- | -----------------: |
| C        | Newton    |       1.5213797068 |
| Python   | Newton    |       1.5213797068 |
| C        | Brent     |       1.5213797068 |
| Python   | Brent     |       1.5213797068 |

| Implementación  | 1.000.000 ejecuciones |
| --------------- | --------------------: |
| C + Newton      |               0.104 s |
| C + Brent       |               0.002 s |
| Python + Newton |               2.061 s |
| Python + Brent  |               4.173 s |

### ¿Qué demuestra el experimento?

Con las pruebas realizadas se puede observar que la diferencia entre C y Python se nota principalmente cuando el mismo cálculo se repite muchas veces. 
Esto no significa que C sea simplemente “mejor” que Python, sino que cada lenguaje tiene una forma diferente de ejecutar el programa.

En este caso, C primero compila el código y lo convierte en instrucciones que puede ejecutar directamente el procesador. 
Además, al utilizar una opción como -O2, el compilador puede aplicar algunas optimizaciones. Python, en cambio, ejecuta el programa mediante su entorno de ejecución, 
por lo que existe un costo adicional en cada una de las operaciones. Cuando el programa es pequeño esta diferencia puede ser difícil de notar, pero al realizar cientos
de miles o millones de cálculos termina siendo más evidente.

Algo que también se debe tener en cuenta es que el resultado numérico no cambia por utilizar uno u otro lenguaje. 
Tanto C como Python pueden encontrar la raíz de la función con prácticamente el mismo valor. La diferencia que se 
está midiendo en el experimento está principalmente relacionada con el tiempo que necesita cada implementación para realizar el cálculo.


**Comparación de los métodos**

**Newton-Raphson utiliza** la siguiente expresión:

$$
x_{n+1}=x_n-\frac{f(x_n)}{f'(x_n)}
$$

Una de sus ventajas es que puede llegar rápidamente a la raíz cuando el valor inicial está cerca de ella. 
En el problema utilizado esto funciona bastante bien. El inconveniente es que el método depende de la derivada y de la elección del punto inicial. 
Si se comienza desde un valor poco adecuado, puede tardar más en converger o incluso no encontrar la raíz.

**Brent-Dekker** utiliza una combinación de tres estrategias:

Bisección.
Método de la secante.
Interpolación cuadrática inversa.

La idea es aprovechar los métodos que pueden avanzar más rápido cuando las condiciones son buenas, pero mantener la bisección como una alternativa cuando esos pasos no resultan convenientes. 
Por esta razón, Brent-Dekker suele ser una opción bastante confiable para encontrar raíces dentro de un intervalo conocido.

### Conclusión

Con el experimento se pudo comprobar que C tuvo un menor tiempo de ejecución que Python al repetir muchas veces los mismos cálculos.
Esto se debe principalmente a la forma en que cada lenguaje ejecuta el programa, ya que C se compila antes de ejecutarse, mientras 
que Python tiene un costo adicional durante la ejecución. Aun así, los dos obtuvieron prácticamente el mismo resultado para la raíz.
En general, el experimento muestra que la elección depende tanto del lenguaje como de las características del problema que se quiera resolver.

