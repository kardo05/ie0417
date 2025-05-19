
# Laboratorio 5 - Despliegue de una aplicación Django con Docker

**Curso**: IE-0417 - Diseño de Software para Ingeniería  
**Universidad de Costa Rica**  
**Nombre del estudiante**: Ricardo Hidalgo Campos  
**Fecha**: 22 de Mayo

## Descripción general

Este laboratorio tiene como objetivo desplegar una aplicación Django utilizando Docker y Docker Compose, haciendo énfasis en la infraestructura, persistencia de datos y configuración de red entre contenedores. Aunque la aplicación Django es básica, el foco principal está en que la solución sea reproducible, aislada y funcional con un solo comando.

## Estructura del proyecto

El proyecto se organiza de la siguiente manera:

- `app/`: Carpeta con la aplicación Django, incluye `Dockerfile`, código fuente, migraciones y configuraciones.
- `docker-compose.yml`: Archivo para orquestar los servicios de Django y PostgreSQL.
- `.env`: Variables de entorno para definir parámetros de la base de datos.
- `README.md`: Informe técnico del laboratorio.

## Explicación de archivos clave

### Dockerfile

Define una imagen personalizada de Python 3.9 para correr Django, instalar dependencias desde `requirements.txt`, recolectar archivos estáticos y exponer el puerto 8000. Utiliza Gunicorn como servidor WSGI.

### docker-compose.yml

Orquesta dos contenedores:
- `web`: Construido desde la carpeta `app/`, ejecuta migraciones y levanta el servidor Gunicorn.
- `db`: Usa una imagen de PostgreSQL 13 con configuración de credenciales desde el archivo `.env`. Almacena datos de manera persistente con un volumen `postgres_data`.

Ambos contenedores comparten la red `app_network`, definida como tipo bridge.

### .env

Contiene las siguientes variables de entorno:
- POSTGRES_DB
- POSTGRES_USER
- POSTGRES_PASSWORD

Estas variables son utilizadas por los servicios definidos en `docker-compose.yml`.

### requirements.txt

Incluye las dependencias del entorno:
- Django 4.0
- psycopg2-binary
- gunicorn
- whitenoise

### Código Django

La aplicación Django tiene una app llamada `notes`, con un modelo básico `Note` que contiene título, contenido y fecha de creación. Se incluye una vista y una plantilla que lista las notas.

## Diagrama de arquitectura

Insertar imagen: `diagrama_arquitectura.png`

Este diagrama muestra la interacción entre el contenedor de la base de datos y el de la aplicación web, conectados por una red Docker, y el uso del volumen para persistencia.

## Instrucciones de ejecución

1. Clonar el repositorio o copiar los archivos del proyecto en una carpeta local.
2. Asegurarse de tener Docker y Docker Compose instalados.
3. Ejecutar el siguiente comando desde la raíz del proyecto:

docker-compose up --build

4. En otra terminal, aplicar las migraciones:

docker-compose exec web python manage.py migrate

5. Crear un superusuario para acceder al panel de administración:

docker-compose exec web python manage.py createsuperuser
user: admin
password: admin123

6. Abrir un navegador y acceder a:

- http://localhost:8080 para ver la lista de notas.
- http://localhost:8080/admin para el panel de administración.

7. Verificar persistencia deteniendo los contenedores con `docker-compose down` y volviéndolos a iniciar con `docker-compose up`. Las notas agregadas deberían seguir presentes.

## Capturas de pantalla

Insertar imagen: `localhost.png`  
Insertar imagen: `localhost_admin.png`

## Verificación de requisitos

- Uso correcto de volúmenes para persistencia ✔️
- Configuración de red entre contenedores ✔️
- Imagen personalizada en Dockerfile ✔️
- Docker Compose funcional y con dependencias ✔️
- Variables de entorno gestionadas correctamente ✔️
- Aplicación accesible desde el navegador ✔️
- Diagrama de arquitectura presente ✔️
- Ejecutable con un solo comando ✔️

## Conclusión

Este laboratorio refuerza conceptos clave en despliegue de aplicaciones mediante Docker, mostrando cómo crear un entorno modular, aislado, reproducible y listo para producción. Se aplicaron buenas prácticas de configuración, uso de redes, manejo de dependencias y persistencia de datos.
