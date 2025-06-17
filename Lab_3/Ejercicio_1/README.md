Github no me permitió subir los proyectos enteros porque me da error de que los nombres de los archivos son muy largos 
(todo el directorio más el nombre del archivo). Por eso subí sólo la carpeta main de cada proyecto.

El proyecto "hello_world" es el del ejemplo proporcionado por TensorFlow Lite Micro incluido en el enunciado.
Creando ese mismo proyecto, tal cual nos dicen en el enunciado, y reemplazando los archivos de main con los de este 
repositorio se obtendrá el proyecto con el que trabajé. Esto simplemente añade la librería esp_timer en el CMAKEFILE y
en el archivo main_functions.cc para calcular el tiempo de inferencia del ejemplo (también está el código para 
calcular el tiempo de todo el proceso en el archivo main.cc, pero este está comentado).

El proyecto "new_hw" es el algoritmo del modelo de "hello_world" implementado en c. Para este, se necesita crear el 
proyecto ingresando los siguientes comandos en wsl:
  - idf.py create-project new_hw
  - cd new_hw/
  - idf.py add-dependency "esp-tflite-micro"    // No estamos seguros de que sea realmente necesario. Pero lo tenemos
                                                    de igual forma por si acaso.
Luego de eso, se copian los archivos de main del repositorio al main del proyecto, y de esta forma estará listo el
proyecto para buildear.

Con respecto a los archivos que están en esta carpeta, el "hello_world_float.tflite" es la topología modelo obtenido 
del enunciado. Es necesario para correr el programa "extracts_weights.py" que lee el archivo y extrae los pesos y 
bias del modelo para finalmente imprimirlos en el archivo de texto "weights.txt".
Este último archivo contiene los datos que se introducen en el archivo "weights_bias.h" de la carpeta main del 
proyecto "new_hw".

INCISO IMPORTANTE
En mi caso, mi pc no aguantaba buildear trabajos con TensorFlow Lite Micro, me daba el siguiente error al intentarlo:
fatal error: Killed signal terminated program cc1plus
Al hacer idf.build mi CPU, SSD y RAM se elevaban al 100% y al parecer el compilador hace un corte de pánico al build.
Con ayuda de ChatGPT obtuve una solución, y es que me sugirió hacer unos cambios antes de buildear.
Primero, me hizo ingresar el siguiente código en wsl:
  - sudo fallocate -l 8G /swapfile
  - sudo chmod 600 /swapfile
  - sudo mkswap /swapfile
  - sudo swapon /swapfile
// No entiendo bien qué hace esto, pero parece que aumenta el SWAP(?) del wsl para aligerar el uso de recursos.
Y luego, me hace buildear de la siguiente forma:
  - IDF_MAKE_NINJA_ENV=1 IDF_NINJA_FLAGS="-j2" idf.py build
// Esto hace que se limite la compilación al uso de 2 hilos, lo que reduce el uso de CPU y RAM

Aclaro esto para indicar que quizás mis resultados salgan diferentes al de los demás por el hecho de tener que 
configurar el uso de recursos de mi ordenador. Pero esta era la única manera que me permitió trabajar.
