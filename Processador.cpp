#include "Processador.h"
#include "Motor.h"
#include <Arduino.h>
#include "RpmInformation.h"

// Respostas
#define ERRO_COMANDO_INVALIDO "ERRO: COMANDO INEXISTENTE\n"
#define ERRO_PARAMETRO_AUSENTE "ERRO: PARÂMETRO AUSENTE\n"
#define ERRO_PARAMETRO_INCORRETO "ERRO: PARÂMETRO INCORRETO\n"

#define RESPOSTA_VENTILADOR "OK VENT\n"
#define RESPOSTA_EXAUSTOR "OK EXAUST\n"
#define RESPOSTA_PARA "OK PARA\n"

// Comandos 
#define AJUSTE_VELOCIDADE "VEL " // concatenar com a velocidade
#define VENTILADOR "VENT"
#define EXAUSTOR "EXAUST"
#define PARAR "PARA"
#define LER_VELOCIDADE "RETVEL"

Processador::Processador(int a) {

}

String Processador::processarComando(String comando, Motor motor, RpmInformation rpm) {

      digitalWrite(13, HIGH);
    if (comando == NULL) {
        return "";
    }
        // Detecta se é um parâmetro
    if (comando.indexOf("VEL ") != -1) {

      // Constante para podermos utilizar o método length na linha abaixo      
      String constant = "VEL ";
      // Extrai a substring contendo o valor da velocidade
      String valor = comando.substring(constant.length());

      // Se não houver velocidade joga o erro de parâmetro ausenete e se o valor for acima de 100 joga o erro de parâmetro incorreto
      if(valor.length() == 0) {
            return ERRO_PARAMETRO_AUSENTE;
        } else if (valor.toInt() > 100 ) {
            return ERRO_PARAMETRO_INCORRETO;
        } else {
        	return "OK VEL " + valor + "\n";
          motor.girar(valor.toInt() * 2.55);
        }
    }

      	// Detecta se é um dos comandos possíveis	
    else if (comando.compareTo(VENTILADOR) == 0) {
        motor.parar();
        motor.ventilador();
        return RESPOSTA_VENTILADOR;
    } else if(comando.compareTo(EXAUSTOR) == 0) {
        motor.parar();
        motor.exaustor();
        return RESPOSTA_EXAUSTOR;
    } else if(comando.compareTo(PARAR) == 0) {
        motor.parar();
        return RESPOSTA_PARA;
    } else if(comando.compareTo(LER_VELOCIDADE) == 0) {
        return"VEL: " + String(rpm.getRpm()) + " RPM\n";
    // Se não foi reconhecido, é invalido
    } else {
    	return ERRO_COMANDO_INVALIDO;
    }
}