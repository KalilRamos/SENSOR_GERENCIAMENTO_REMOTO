
# Introdução Rápida

* Esse projeto tem como objetivo a confecção de um circuíto de monitoramento para nos ajudar a monitorar as OLTs localizadas em vários pontos pela cidade, esse projeto está sendo realizado com ajuda da empresa a qual trabalho atualmente FIXTELL TELECOM. Com esse monitoramento será possível corrigir potenciais problemas antes que afetem nossos clientes, aos poucos vamos adicionando mais funções no circuíto, sendo assim, é possível que o ele sofra alterações com o tempo, porém quaisquer alterações feitas, postaremos aqui no github.

  
* Iremos deixar os códigos o mais comentado possível, para que os interessados no projeto tenham o mínimo de dificuldade possível na compreenssão do mesmo, se sintam livres para fazer críticas construtivas e sugestões ao projeto, vou deixar aqui o meu número pessoal para que possam me contatar mais facilmente. 98 99189-0978 (Kalil).



# Protótipo 1
![Imagem do WhatsApp de 2024-09-20 à(s) 11 54 36_1ebbca85](https://github.com/user-attachments/assets/a99d62ac-5b19-4626-9752-e229662b8479)

* Nesse primeiro protótipo buscamos desenvolver um sensor de temperatura e humidade para monitorarmos o aquecimento dos dispositivos usados na nossa empresa

* Por agora usamos os seguintes componentes:
  * 1- ESP32 Doit Kevit V1 ;
  * 2- 2 leds, verde e vermelho ;
  * 3- 2 séries de resistores com 3 resistores de 330 Ohns cada ;
  * 4- Buzzers passivo e ativo ;
  * 5- Sensor de temperatura e umidade DHT11 ;


  ## Simulação virtual do circuíto no tinkercad
![image](https://github.com/user-attachments/assets/fa503f69-9d4a-480a-a70f-7ee595b908e9)

* Utilizamos a simulação para testar algumas funcionalidades antes de montar no circuíto físico.


# Protótipo 2

![Imagem do WhatsApp de 2024-10-14 à(s) 12 24 39_8e10e9f1](https://github.com/user-attachments/assets/906de519-2202-401a-bef8-110fa1601e79)

* No protótipo 2 foi colocada uma fonte de 12 volts conectada na tomada para que o circuíto fique ligado sem a necessidade de estar conectado a um computador.



# Protótipo 3

![Imagem do WhatsApp de 2024-10-14 à(s) 12 19 59_1c2be098](https://github.com/user-attachments/assets/2a8189d3-fb7b-459e-9981-4862fe62a7cd)

* O circuíto do protótipo 3 é igual ao protótipo 2, porém ele foi integrado a plataforma arduíno cloud, fazendo com que consigamos monitorar a temperatura remotamente e também a produção de relatórios em csv com os dados acumulados (dia, hora, temperatura).



# Protótipo 4

![image](https://github.com/user-attachments/assets/d35c2c85-06eb-468c-bd9d-992d4a4b143d)        ![Imagem do WhatsApp de 2024-10-17 à(s) 10 24 36_13dc870b](https://github.com/user-attachments/assets/4117d69b-6177-4198-8fb7-12455e697fc8)

* No protótipo 4 realizamos mais uma integração com o arduíno cloud, porém agora para monitorar tanto a temperatura quanto a umidade remotamente, gerando gráficos da variação de temperatura (Vartemp) e umidade (Varumid) e produzindo relatórios semelhantes aos do protótipo anterior, porém agora adicionando os valores acumulados da umidade


# Protótipo 5

* O protótipo 5 está em produção, porém a ideia é que ele contará com as mesma funcionalidades dos protótipos anteriores, porém ele será integrado com outro circuito para que ele possa nos alertar através do circúito secundário se o sensor está ativo ou não, assim poderemos saber se a energia do local caiu ou não.

