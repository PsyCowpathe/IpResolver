/*Addresse Ip et ses classes*/

L'addresse ip est constitue de l addresse réseau ET de la machine.

une ip qui commence par 0xx.xxx.xxx.xxx est de classe A
une ip qui commence par 10x.xxx.xxx.xxx est de classe B
une ip qui commence par 110.xxx.xxx.xxx est de classe C


/*Masque de sous reseau*/

Le masque sert a identifier quel parti de l'addresse ip represente le reseau et quel parti represente la machine (avec un ET logique).
Masque en 32 bits, un bit a 1 represente la parti reseau et un bit a 0 represente la machine 
Un masque est valide seulement si les bits a 1 et a 0 ne se melange pas (les 1 toujours a gauche)

Masque = 255.255.0.0 -> [11111111.11111111].(00000000.00000000)
Add Ip = 192.168.0.1 -> [11000000.10101000].(00000000.00000001)

						   [Reseau] (Machine)

/*Nombre d'addresse*/

2^nombre de bit a 0 - 2 (-2 car on ne peut pas attribuer l'addresse du sous-reseau et l'addresse de diffusion

Si j'ai un masque 10.0.0.0/16	/16 represente le nombre de bits a 1 donc je peut deduire le nombre de bits a 0 et
realiser le calcul suivant : 2^16 = 65 536 j'ai donc 65 536 addresse ip dans ma plage reseau

/*Premiere et dernierre addresse d'une plage d'ip*/

j'ai une ip 192.168.0.1 avec un masque 255.224.0.0

192.168.0.1 = 11000000.10101000.00000000.00000001
255.224.0.0 = 11111111.11100000.00000000.00000000

premiere addresse = changer tous les bits 1 a 0 de l'ip correspondant a la parti machine :

11000000.10100000.00000000.00000000 = 192.160.0.0

derniere addresse (addresse de broadcast) = changer tous les bits de 0 a 1 de l'ip correspondant a la parti machine :

11000000.10111111.11111111.11111111 = 192.191.255.255

Notre plage reseau est donc 192.160.0.0 - 192.191.255.255


/*Calcul du masque*/

j'ai besoin d'une plage reseau avec un minimum de 1000 ip

je multipli le nombre de bits (32) par 32 pour obtenir un multiple de 32 superieur a 1000
32 x 32 = 1024
1024 en binaire = 10000000000
j'ai donc besoin d'un mask qui contien 10 bits a zero donc 32 bits a 0 et le reste a 1

 11111111.11111111.11111100.00000000 converti en decimal --> 255.255.252.000

 /*Modele OSI*/

C'est une norme qui encadre la facon de communiquer des ordinateurs
Il est compose de 7 couches, chacune de ces couches est un element necessaire a etablir une communication.
Permet une compatibilite entre les differents constructeurs 
Permet une evolution de la communication car les differentes couches sont independantes et donc peuvent evoluer/etre remplacer sans avoir a remplacer toutes les autres couches

/*Couches*/

C1 = Physique : offre un support de transmision
C2 = liaison de donnee : connecter les machines entre elles en reseau locale
C3 = Reseau : interconnecter les reseau entre eux
C4 = Transport : gerer les connexions
C7 = Application : represente les applications 

/*Modele actuel d'internet*/

Utilise tcp/ip sur 4 couches, modele DOD

/*Protocoles TCP/IP*/

Un protocoles est un mode operatoire de communication qui doit etre commun a tous les elements qui souhaite communiquer entre eux.

Protocoles de dialogue entre app cliente et serveur (couche 4) : HTTP, FTP, POP, SMTP
Protocoles de transport de donnees (couche 3) : TCP, UDP
Protocoles de routage des informations entre reseau (couche 2) : IP, ICMP

UDP = protocole de transfert de donnee, moins gourmand en ressource que le tcp mais pas efficace pour les gros transfert de donnee car pas de confirmation de reception
TCP = protocole de transfert de donnee il permet le transfert de donnee dans de bonen conditions, "Chaque fois que tu envoies un message à son destinataire, assure-toi qu'il l'a reçu et compris"
ICMP = protocole qui permet de controler les anomalies de transfert de donnee
SMTP = protocole d'acheminement de mail depuis le serveur smtp

/*DNS*/

Permet de traduire le Full Qualified Domain Name en addresse ip pour accedder aux site web par exemple. ces serveur sont souvent des DNS recursif (avec une ip fourni par le protocole DHCP) qui savent faire les recherche necessaire pour resoudre n'importe quel nom d'hotes

/*DHCP*/

Protocole qui allou dynamiquement une addresse ip a un systeme informatiquequi se connecte au reseau, il fournit egalement la passerelle par defaut et le DNS.

/*Notation CIDR*/

xxx.xxx.xxx.xxx/23

represente le nombre de bits a 1 du masque de sous reseau

ex ip = 233.249.146.36 masque = 255.255.254.0 = 11111111.11111111.11111110.00000000

cidr = 233.249.146.36/23

/*TCP/UDP*/

UDP = User Datagram Protocol
UDP est un protocole oriente datagramme, un datagaramme est un paquet de donnee generalement
utilise pour designer une systeme de transmissions non fiable car le protocole ne garanti pas l'arrive du paquet contrairement a

TCP = Transmission Control Protocol
TCP est un protocole de transmission de donnee de maniere connecte, c'est a dire qu'il garanti la bonne reception des paquets entre deux machine grace a sont fonctionnement en trois phases : 
		
		-établissement de la connexion
		-transferts de données 
		-fin de la connexion




123.48.189.194
01111011.00110000.10111000.00000000

11111111.11111111.11111000.00000000
