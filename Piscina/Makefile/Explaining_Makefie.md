```
/Proyecto
│
├── /srcs                   # Carpeta donde se encuentran los archivos fuente del proyecto
│   ├── outputs.c
│   ├── parsing.c
│   ├── binaries.c
│   └── t_print.c
│
├── /libft                  # Carpeta de la biblioteca auxiliar libft
│   ├── libft.h             # Archivo de cabecera de la biblioteca
│   ├── libft.a             # Biblioteca estática (se genera tras compilar libft)
│   ├── /srcs               # Archivos fuente de libft
│   │   ├── ft_atoi.c
│   │   ├── ft_strlen.c
│   │   ├── ft_strcpy.c
│   │   └── ...             # Más archivos fuente de libft
│   ├── /objs               # Archivos objeto (.o) de libft (se generan tras compilar)
│   │   ├── ft_atoi.o
│   │   ├── ft_strlen.o
│   │   └── ft_strcpy.o
│   └── Makefile            # Makefile específico de la biblioteca libft
│
├── /objs                   # Archivos objeto del proyecto principal (se generan tras compilar)
│   ├── outputs.o
│   ├── parsing.o
│   ├── binaries.o
│   └── t_print.o
│
├── /includes               # Archivos de cabecera del proyecto (opcional, si se utilizan)
│   ├── project.h           # Archivo de cabecera del proyecto
│   └── ...                 # Otros archivos de cabecera si los hay
│
├── Makefile                # Makefile principal del proyecto
└── nombre_programa.a        # Archivo de salida final del proyecto (se genera tras compilar)
```

### Descripción de las carpetas y archivos:

1. **`/srcs`**:
   - Carpeta que contiene los archivos fuente (`.c`) del proyecto principal. Aquí se encuentran los archivos `outputs.c`, `parsing.c`, `binaries.c` y `t_print.c`, que son compilados en archivos `.o` (objetos) para la creación del programa o biblioteca final.

2. **`/libft`**:
   - Contiene la biblioteca auxiliar `libft` que se incluye en el proyecto.
   - Dentro de esta carpeta se encuentra:
     - **`libft.h`**: El archivo de cabecera que define las funciones de la biblioteca.
     - **`libft.a`**: El archivo final de la biblioteca estática, que se genera después de compilar.
     - **`/srcs`**: Carpeta con los archivos fuente de `libft`.
     - **`/objs`**: Carpeta donde se almacenan los archivos objeto `.o` generados al compilar `libft`.
     - **Makefile**: Un archivo Makefile específico para compilar la biblioteca `libft`.

3. **`/objs`**:
   - Carpeta que contiene los archivos objeto (`.o`) del proyecto principal. Estos archivos se generan al compilar los archivos fuente del proyecto y son utilizados para crear la biblioteca o ejecutable final.

4. **`/includes`** (opcional):
   - Si el proyecto utiliza archivos de cabecera (`.h`) que definen funciones o estructuras utilizadas en el código, estos se pueden encontrar en esta carpeta. Un ejemplo sería `project.h`.

5. **Makefile**:
   - El archivo Makefile principal que controla la compilación del proyecto.

6. **`nombre_programa.a`**:
   - Este es el archivo final que genera el proyecto. Dependiendo del proyecto, podría ser una biblioteca estática (archivo `.a`) o un ejecutable.

### Explicación de cómo encaja con el Makefile:

- **Archivos fuente (`outputs.c`, `parsing.c`, etc.)** se encuentran en la carpeta `/srcs` y son convertidos en archivos objeto (`outputs.o`, `parsing.o`, etc.) en la carpeta `/objs`.
- **La biblioteca `libft`** tiene su propio directorio `/libft`, que contiene sus archivos fuente y su propio Makefile. Al ejecutar la regla `pmake`, se invoca el Makefile de `libft` para compilar su código y generar el archivo `libft.a`.
- **Los archivos objeto del proyecto y de `libft`** se combinan en un único archivo final, que sería la salida del proyecto (`nombre_programa.a`).


---

Este Makefile está diseñado para gestionar eficientemente la compilación, limpieza y reconstrucción de un proyecto en C, junto con su biblioteca auxiliar `libft`.


NAME        = libftprintf.a

SRCS_PATH   = srcs/

LIBFT_PATH  = libft/

LIBFT_LIB   = libft.a

HEADERS_FOLDER    = includes/

SRCS_FILES  = $(addprefix ${SRCS_PATH},\
                  conversions.c \
                  extra.c \
                  fields.c \
                  ft_printf.c \
                  bases.c \
                  inisialization.c \
                  outputs.c \
                  parsing.c \
                  binaries.c \
                  t_print.c )

SRCS_OBJS   = ${SRCS_FILES:.c=.o}

CC          = gcc

CFLAGS            = -Wall -Wextra -Werror

RM          = rm -f

AR          = ar crs

LIBFT_OBJS  = ${LIBFT_PATH}*.o

LIBFTMAKE   = $(MAKE) -C ${LIBFT_PATH}

all:        ${NAME}

${NAME}:    ${SRCS_OBJS} pmake
            ${AR} ${NAME} ${SRCS_OBJS} ${LIBFT_OBJS}

pmake:
            ${LIBFTMAKE}

clean:
            make -C ${LIBFT_PATH} clean
            ${RM} ${SRCS_OBJS}

fclean:           clean
            ${RM} ${NAME} ${LIBFT_PATH}${LIBFT_LIB}

re:         fclean all

.PHONY:           all clean fclean re

---



### **Definición de archivos y variables:**

1. **Archivos fuente (`outputs.c`, `parsing.c`, `binaries.c`, `t_print.c`):**
   - Son los archivos que contienen el código fuente en C del proyecto. Estos archivos serán compilados para generar archivos objeto (.o) en el proceso de compilación.

2. **`SRCS_OBJS` = `${SRCS_FILES:.c=.o}`:**
   - Esta variable utiliza una sustitución de sufijo para convertir cada archivo fuente `.c` en su correspondiente archivo objeto `.o`. Es decir, si tienes un archivo `outputs.c`, esta regla lo convierte en `outputs.o`.
   - Así que, por ejemplo, `SRCS_FILES = outputs.c parsing.c binaries.c t_print.c` se convertirá en `SRCS_OBJS = outputs.o parsing.o binaries.o t_print.o`.

3. **`CC = gcc`:**
   - Define el compilador a utilizar, en este caso es `gcc` (GNU Compiler Collection). Este compilador será utilizado para compilar los archivos `.c` a archivos `.o`.

4. **`CFLAGS = -Wall -Wextra -Werror`:**
   - Define los "flags" o opciones del compilador. En este caso:
     - `-Wall`: Activa todas las advertencias importantes del compilador.
     - `-Wextra`: Activa advertencias adicionales que no están incluidas en `-Wall`.
     - `-Werror`: Trata todas las advertencias como errores, lo que significa que el código no se compilará si tiene advertencias.

5. **`RM = rm -f`:**
   - Define el comando para eliminar archivos, en este caso `rm -f`, que elimina archivos de manera forzada (sin pedir confirmación) y no genera errores si el archivo no existe.

6. **`AR = ar crs`:**
   - Define el comando para crear archivos de bibliotecas estáticas. `ar` es una herramienta para crear, modificar y extraer archivos de bibliotecas estáticas en Unix.
     - `c`: Crea la biblioteca si no existe.
     - `r`: Inserta archivos en la biblioteca.
     - `s`: Crea un índice en la biblioteca para facilitar la búsqueda.

7. **`LIBFT_OBJS = ${LIBFT_PATH}*.o`:**
   - Define todos los archivos objeto (`*.o`) en el directorio especificado por `LIBFT_PATH`. Estos archivos probablemente pertenezcan a la biblioteca `libft`, una biblioteca auxiliar de funciones que es común en proyectos de C.

8. **`LIBFTMAKE = $(MAKE) -C ${LIBFT_PATH}`:**
   - Define el comando para ejecutar `make` en el directorio de `LIBFT_PATH`, lo que indica que también se compilará el código de la biblioteca `libft` usando su propio Makefile.

---

### **Reglas del Makefile:**

1. **`all: ${NAME}`**
   - Esta es la regla principal del Makefile. Indica que la meta por defecto es construir el archivo especificado por la variable `NAME`. En este caso, `NAME` es la salida del programa, que generalmente es un archivo ejecutable o una biblioteca.

2. **`${NAME}: ${SRCS_OBJS} pmake`**
   - Esta regla define que para construir el objetivo `NAME` (el archivo final o la biblioteca), primero se deben compilar todos los archivos fuente (`${SRCS_OBJS}`) y luego ejecutar la regla `pmake`.
   - Luego utiliza el comando `${AR}` para crear una biblioteca estática que incluye los objetos del proyecto (`${SRCS_OBJS}`) y los de la biblioteca `libft` (`${LIBFT_OBJS}`).

3. **`pmake:`**
   - Esta regla llama a `${LIBFTMAKE}`, lo que significa que invoca el `make` en el directorio de la biblioteca `libft`. Es decir, compila `libft` antes de crear el archivo final.

4. **`clean:`**
   - Esta regla se encarga de limpiar los archivos compilados generados durante la construcción del proyecto. 
   - Primero ejecuta `make clean` dentro del directorio de `libft` para limpiar los objetos de esa biblioteca.
   - Luego, utiliza `${RM}` para eliminar los archivos `.o` del proyecto principal.

5. **`fclean: clean`**
   - La regla `fclean` hace lo mismo que `clean`, pero además elimina el archivo final (`${NAME}`) y la biblioteca de `libft` (`${LIBFT_LIB}`).

6. **`re: fclean all`**
   - Esta regla primero ejecuta `fclean` (elimina todos los archivos objeto y el archivo final) y luego ejecuta `all`, lo que fuerza una recompilación completa del proyecto desde cero.

---

### **`.PHONY:`**
   - Esta es una etiqueta especial que indica que las reglas que siguen (`all`, `clean`, `fclean`, `re`) no corresponden a archivos reales en el sistema de archivos. Esto evita problemas en caso de que existan archivos con los mismos nombres que estas reglas.

---

### **Proceso de compilación explicado paso a paso:**

1. **Compilación inicial (`all`):**
   - Cuando ejecutas `make`, la regla por defecto es `all`. Esta intenta crear el archivo `NAME`.
   - Para ello, primero compila todos los archivos `.c` en archivos `.o` utilizando `gcc` con las opciones especificadas en `CFLAGS`.
   - Luego llama a la regla `pmake`, que compila la biblioteca `libft` si es necesario.
   - Finalmente, utiliza el comando `ar` para crear la biblioteca o archivo final combinando los archivos `.o` del proyecto y los de `libft`.

2. **Limpieza (`clean` y `fclean`):**
   - Si ejecutas `make clean`, se eliminarán los archivos `.o` tanto del proyecto principal como de la biblioteca `libft`.
   - Si ejecutas `make fclean`, además de eliminar los archivos `.o`, también se elimina el archivo final (`NAME`) y cualquier otra salida de la biblioteca `libft`.

3. **Reconstrucción (`re`):**
   - Si ejecutas `make re`, el proyecto se limpia por completo con `fclean` y luego se recompila desde cero.



