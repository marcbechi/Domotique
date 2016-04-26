# Domotique
Projet Final Domotique



Dans le cadre de la formation licence professionnelle automatique et informatique industrielle, nous avons à réaliser un projet domotique. 
Nous avons choisi de réaliser un robot suiveur de ligne, détecteur de couleur et anti collision. Le but de ce projet et de programmer, comprendre les capteurs que nous allons utiliser et de pouvoir commander un robot à l’aide d’un site web connecté en Wi-Fi, le laisser réaliser un chemin en suivant une ligne blanche, ou qu’il suive une ligne coloré. 
Au fur et à mesure le projet a évolué. Dans un premier temps, nous avons travaillé à l’aide d’une carte de programmation Arduino, de type Mega. Le but était de tester dans un premier temps les différents capteurs que nous souhaitons ensuite appliquer à un ESP8266 V1.0 qui embarque un microcontrôleur et un module Wifi.
Quant à l’ESP8266, nous avons testé la connexion en websocket avec une application Android. 



Dans un premier temps nous allons voir le matériel mit à notre disposition. 

Pour réaliser les tests des différents capteurs nous un Arduino Micro. 
Voici la liste des capteurs utilisés :

-	Capteur de couleur
-	Hacheur
-	Capteur ultrason 
-	Boussole 

Dans un premier temps nous allons analyser le capteur de couleurs ainsi que son code. 

Voici le capteur de couleur

Comme vous pouvez le voir, on retrouve ici les différents pins qui sont à câbler sur notre Arduino. 
On retrouve une alimentation Vcc, la masse GND, des sortie S0, S1, S2, S3, E0, et OUT

![](https://github.com/marcbechi/Domotique/blob/master/Images%20Rapport/IMG_20160331_104219.jpg)

Capteur de couleur basé sur le circuit TCS3200 et 4 leds blanches. Le capteur délivre une fréquence en fonction de la couleur. Il est constitué de 4 filtres pour chaque couleur, la fréquence de sortie est proportionnelle à la couleur choisie.

Le module se raccorde sur 5 E/S digitales pour la sélection du filtre et la mesure de la fréquence de sortie d'une carte compatible Arduino. Il peut s'utiliser avec une plaque de montage sans soudures.
Alimentation: 3 à 5 Vcc


[http://dsp.stackexchange.com/questions/8949/how-do-i-calculate-the-color-temperature-of-the-light-source-illuminating-an-ima](http://dsp.stackexchange.com/questions/8949/how-do-i-calculate-the-color-temperature-of-the-light-source-illuminating-an-ima)

Nous avons ensuite les hacheurs. 
Le hacheur est un dispositif de l'électronique de puissance mettant en œuvre un ou plusieurs interrupteurs électroniques commandés ce qui permet de modifier la valeur de la tension d'une source de tension continue avec un rendement élevé.
 




Ici on utilise ce hacheur :

![](https://github.com/marcbechi/Domotique/Images Rapport/blob/master/Images%20Rapport/IMG_20160331_104147.jpg)


On envoie deux signaux pour 1 moteur la masse et Vcc.
On branche deux moteurs sur chaque module. 
 



# Capteur Ultrason

Nous allons réaliser un montage simple permettant de comprendre le fonctionnement du capteur ultrason HC-SR04.
Pour ce montage, les éléments sont:
•	Arduino UNO
•	Capteur ultrason
Le montage électrique:
 
![](https://github.com/marcbechi/Domotique/blob/master/Images%20Rapport/Montage%20arduino%20ultrason.png)


Nous avons également testé une boussole HMC5883L. Elle possède 5pins : 

![](https://github.com/marcbechi/Domotique/blob/master/Images%20Rapport/Montage%20arduino%20boussole.png)

Ce capteur permet d’avoir la position angulaire comme une véritable boussole.  Il est possible d’avoir un affichage graphique à l’aide d’un autre logiciel de programmation qui est Processing. Plus d’information sur le site suivant : (http://arduikyo.blogspot.fr/2013/08/hmc5883l-compass-arduino-processing.html)

Voici les différents codes utilisés : 

[Détection de la couleur ](https://github.com/marcbechi/Domotique/blob/master/Codes%20Arduino/Capteur_de_couleur/Capteur_de_couleur.ino)

[Code capteur Ultrason](https://github.com/marcbechi/Domotique/blob/master/Codes%20Arduino/Capteur_ultrason/Capteur_ultrason.ino)

[Code Hacheur couplé à l'ultrason](https://github.com/marcbechi/Domotique/blob/master/Codes%20Arduino/Hacheur_couple_ultrason/Hacheur_couple_ultrason.ino) 


# ESP8266 Installation Arduino
Projet Final Domotique


Le but de ce projet est de programmer un  ESP8266 avec le code exécuté sur notre arudino UNO afin d'avoir une communication Wifi comprise dans l'ESP8266.
Pour cela nous nous sommes donc intéressé à la bibliothèque ESP8266 compatible Arduino ainsi que d'autres méthodes que nous allons voir. 

Dans un premier temps nous allons voir le matériel mit à notre disposition. 

Nous avions donc un ESP8266 V1.0 que vous pouvez retrouver en vente sur ce site :
[ESP8266](http://e.banana-pi.fr/fr/recherche?controller=search&orderby=position&orderway=desc&search_query=esp8266)

Un ordinateur ayant Arduino 1.6.8 installé qui est la dernière version à jour d'Arduino :

[Dernière Version d'Arduino](https://www.arduino.cc/en/Main/Software)

Pour ajouter les plug-in nécessaire à l'outils de programmation de l'ESP8266 sur Arduino, je vous invite a suivre les instructions suivantes: 

# 1.
Ajouter le lien de référence au développement de l'ESP8266. 
Pour cela 
`Fichier -> Préférences.`
Copier le lien suivant dans `URL de gestionnaire de cartes supplémentaires` :

`http://arduino.esp8266.com/stable/package_esp8266com_index.json`

# 2.
Pour vérifier si votre lien est correcte, aller dans :
`Outils -> Type de carte -> Gestionnaire de carte`

Lancez la recherche `ESP8266`
Puis Installez 

Pendant ce temps je vous invite à vous boire un petit café si vous êtes matinal, sinon un petit thé fera l'affaire ! 

Une fois installé vous allez avoir accès à toute les fonctionnalités sur Arduino pour programmer votre ESP8266. 
Tous simplement je vous demande de vous dirigez vers `Outils -> Type de carte` 
Descendez jusqu'à la petite flèche et vous verez qeu vous aurez à votre disposition bien plus de type de carte dont la ESP8266 NodeMCU 1.0, correspondant à celle du site que je vous ai partagé précédemment. 

Selectionné la. 
Une panoplie d'options : 

* La fréquence du CPU : 80MHz ou 16MHz 
* La taille de la mémoire Flash 
* La fréquence de téléversement et communication avec le PC 

Je vous conseille de ne laisser les paramètres de bases si vous n'êtes pas expert, cela ne vous apportera rien de modifier les valeurs. 
Seul le Bauderate peut être utile selon les capteurs que vous utiliserez sur votre ESP8266 NodeMCU 1.0


Vous voilà fin prêt à programmer votre ESP8266 avec Arduino. 
Bonne programmation !! :+1: :+1: :+1:  


# Autre Option : ESP8266 Installation Eclipse Arduino IDE

Pour cette installation je vous invite à suivre le Tuto du créateur qui est très bien fait et assez simple à réaliser.
Il a également fait des vidéos explicatives pour installer son plug-in. 

[Lien Youtube vers ses vidéos](https://www.youtube.com/playlist?list=PLCSjf7QmP3TDPSjT_5UIp0DHXzKdhIQsF)

[Lien vers son site permettant de télécharger le plug-in](http://eclipse.baeyens.it/)

# ESP8266 Websocket Application

Pour commencer à travailler avec l’ESP8266, nous avons récupérer un code de websocket et nous avons modifié ce programme afin de pouvoir communiquer avec, et envoyé un message à l’ESP8266 à l’aide d’un Smartphone Android. 

Sur ce Smartphone Android, nous avons récupéré une application Android sur le Play Store : 

![](https://github.com/marcbechi/Domotique/blob/master/Images%20Rapport/Screenshot_2016-03-31-11-34-45.png)

Cette application permet de se connecter au Websocket de l’ESP8266 et d’envoyer un message. 
