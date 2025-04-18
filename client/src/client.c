#include "client.h"

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	int conexion;
	char* ip;
	char* puerto;
	char* clave;

	t_log* logger;
	t_config* config;

	/* ---------------- LOGGING ---------------- */

	logger = iniciar_logger();
	log_info(logger, "Hola! Soy un log");

	// Usando el logger creado previamente
	// Escribi: "Hola! Soy un log"


	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */

	config = iniciar_config();
	if(!config_has_property(config, "IP")||
	   !config_has_property(config, "PUERTO")||
	   !config_has_property(config, "CLAVE")){
		exit(3);
	};
	clave = config_get_string_value(config, "CLAVE");
	ip = config_get_string_value(config, "IP");
	puerto = config_get_string_value(config, "PUERTO");

	// Usando el config creado previamente, leemos los valores del config y los
	// dejamos en las variables 'ip', 'puerto' y 'valor'

	// Loggeamos el valor de config
	log_info(logger, "Clave: %s, Direccion IP: %s, Numero de Puerto: %s \n", clave, ip, puerto);

	/* ---------------- LEER DE CONSOLA ---------------- */

	leer_consola(logger);
	log_destroy(logger);

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él

	// Creamos una conexión hacia el servidor
	conexion = crear_conexion(ip, puerto);

	// Enviamos al servidor el valor de CLAVE como mensaje

	// Armamos y enviamos el paquete
	paquete(conexion);

	terminar_programa(conexion, logger, config);

	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente
}

t_log* iniciar_logger(void)
{
	t_log* nuevo_logger;
	nuevo_logger = log_create("tp0.log", "TP0", true, LOG_LEVEL_INFO);
	if (nuevo_logger == NULL){
		printf("No se ha podido crear el logger \n");
		exit(1);
	}
	return nuevo_logger;
}

t_config* iniciar_config(void)
{
	t_config* nuevo_config;
	if ((nuevo_config = config_create("./cliente.config")) == NULL){
		printf("No pude leer la config \n");
		abort();
	}
	return nuevo_config;
}

void leer_consola(t_log* logger)
{
	char* linea;
	// La primera te la dejo de yapa
	while (1) {
        linea = readline(">");
		if (linea == NULL || strlen(linea) == 0) {
			free(linea);  // Importante liberar la memoria si readline devuelve una cadena vacía
			break;
		}
		log_info(logger, "%s",linea);
		free(linea);
    }


	// El resto, las vamos leyendo y logueando hasta recibir un string vacío


	// ¡No te olvides de liberar las lineas antes de regresar!

}

void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char* leido;
	t_paquete* paquete;

	// Leemos y esta vez agregamos las lineas al paquete


	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!

}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	/* Y por ultimo, hay que liberar lo que utilizamos (conexion, log y config)
	  con las funciones de las commons y del TP mencionadas en el enunciado */
}
