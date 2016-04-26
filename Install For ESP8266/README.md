# Domotique
Projet Final Domotique


Le but de ce projet est de programmer un  ESP8266 avec le code exécuté sur notre arudino UNO afin d'avoir une communication Wifi comprise dans l'ESP8266.
Pour cela nous nous sommes donc intéressé à la bibliothèque ESP8266 compatible Arduino ainsi que d'autres méthodes que nous allons voir. 

Dans un premier temps nous allons voir le matériel mit à notre disposition. 

Nous avions donc un ESP8266 V1.0 que vous pouvez retrouver en vente sur ce site :
![](http://e.banana-pi.fr/fr/recherche?controller=search&orderby=position&orderway=desc&search_query=esp8266)
Un ordinateur ayant Arduino 1.6.7 installé qui est la dernière version à jour d'Arduino :
![](https://www.arduino.cc/en/Main/Software)

Pour ajouter les plug-in nécessaire à l'outils de programmation de l'ESP8266 sur Arduino, je vous invite a suivre les instructions suivantes: 

# 1.
Ajouter le lien de référence au développement de l'ESP8266. 
Pour cela 
`Fichier -> Préférences.`
Copier le lien suivant dans `URL de gestionnaire de cartes supplémentaires` :

`http://arduino.esp8266.com/stable/package_esp8266com_index.json`

# 2.
Pour vérifier si votre lien est correcte, aller dans :
`Outils -> `
[http://dsp.stackexchange.com/questions/8949/how-do-i-calculate-the-color-temperature-of-the-light-source-illuminating-an-ima](http://dsp.stackexchange.com/questions/8949/how-do-i-calculate-the-color-temperature-of-the-light-source-illuminating-an-ima)

Nous avons ensuite les hacheurs. 
Le hacheur est un dispositif de l'électronique de puissance mettant en œuvre un ou plusieurs interrupteurs électroniques commandés ce qui permet de modifier la valeur de la tension d'une source de tension continue avec un rendement élevé.
 




Ici on utilise ce hacheur :

![](https://github.com/marcbechi/Domotique/blob/master/IMG_20160331_104147.jpg)


On envoie deux signaux pour 1 moteur la masse et Vcc.
On branche deux moteurs sur chaque module. 
Le principe est de 



# Capteur Ultrason

Nous allons réaliser un montage simple permettant de comprendre le fonctionnement du capteur ultrason HC-SR04.
Pour ce montage, les éléments sont:
•	Arduino UNO
•	Capteur ultrason
Le montage électrique:
 
![](https://github.com/marcbechi/Domotique/blob/master/Montage%20arduino%20ultrason.png)


Nous avons également testé une boussole HMC5883L. Elle possède 5pins : 

![](https://github.com/marcbechi/Domotique/blob/master/Montage%20arduino%20boussole.png)

Ce capteur permet d’avoir la position angulaire comme une véritable boussole.  Il est possible d’avoir un affichage graphique à l’aide d’un autre logiciel de programmation qui est Processing. Plus d’information sur le site suivant : (http://arduikyo.blogspot.fr/2013/08/hmc5883l-compass-arduino-processing.html)

Voici les différents codes utilisés : 

[Détection de la couleur ](https://github.com/marcbechi/Domotique/blob/master/Capteur_de_couleur.ino)

[Code capteur Ultrason](https://github.com/marcbechi/Domotique/blob/master/Capteur_ultrason.ino)

[Code Hacheur couplé à l'ultrason](https://github.com/marcbechi/Domotique/blob/master/Capteur_ultrason.ino) 


# ESP8266 Websocket Application

Pour commencer à travailler avec l’ESP8266, nous avons récupérer un code de websocket et nous avons modifié ce programme afin de pouvoir communiquer avec, et envoyé un message à l’ESP8266 à l’aide d’un Smartphone Android. 

Sur ce Smartphone Android, nous avons récupéré une application Android sur le Play Store : 

![](https://github.com/marcbechi/Domotique/blob/master/Screenshot_2016-03-31-11-34-45.png)

Cette application permet de se connecter au Websocket de l’ESP8266 et d’envoyer un message. 
