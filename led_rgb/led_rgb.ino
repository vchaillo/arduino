
// --- Programme Arduino --- 
// Trame de code g�n�r�e par le g�n�rateur de code Arduino
// du site www.mon-club-elec.fr 

// Auteur du Programme : X. HINAULT - Tous droits r�serv�s 
// Programme �crit le : 20/2/2012.

// ------- Licence du code de ce programme ----- 
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License,
//  or any later version.
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

// ////////////////////  PRESENTATION DU PROGRAMME //////////////////// 

// -------- Que fait ce programme ? ---------
 /* Ce programme teste simplement l'affichage des couleurs
sur une LED RVB 5mm � anode commune (+ commun)  

La RVB dispose de 4 broches : 
* une broche de 5V
* une broche de commande du ROUGE
* une broche de commande du VERT
* une broche de commande du BLEU

Chaque broche peut recevoir une impulsion PWM (0-255) pour doser l'intensit� de chacune des couleurs.  
*/

// --- Fonctionnalit�s utilis�es --- 


// -------- Circuit � r�aliser --------- 

// Broche 3 : La broche Rouge de la LED RGB
// Broche 5 : La broche Vert de la LED RGB
// Broche 6 : La broche Bleu de la LED RGB

// /////////////////////////////// 1. Ent�te d�clarative /////////////////////// 
// A ce niveau sont d�clar�es les librairies incluses, les constantes, les variables, les objets utiles...

// --- D�claration des constantes ---

// --- Inclusion des librairies ---

// --- D�claration des constantes utiles ---

const int R=1; 
const int V=1; 
const int B=1;

// --- D�claration des constantes des broches E/S num�riques ---

const int ledRouge=3; // Constante pour la broche 3
const int ledVert=5; // Constante pour la broche 5
const int ledBleu=6; // Constante pour la broche 6

// --- D�claration des constantes des broches analogiques ---


//const int Voie[6]={0,1,2,3,4,5}; //declaration constante de broche analogique


// --- D�claration des variables globales ---


// --- D�claration des objets utiles pour les fonctionnalit�s utilis�es ---


// ////////////////////////// 2. FONCTION SETUP = Code d'initialisation ////////////////////////// 
// La fonction setup() est ex�cut�e en premier et 1 seule fois, au d�marrage du programme

void setup()   { // debut de la fonction setup()

// --- ici instructions � ex�cuter 1 seule fois au d�marrage du programme --- 

// ------- Initialisation fonctionnalit�s utilis�es -------  


// ------- Broches en sorties num�riques -------  
 pinMode (ledVert,OUTPUT); // Broche ledVert configur�e en sortie
 pinMode (ledRouge,OUTPUT); // Broche ledRouge configur�e en sortie
 pinMode (ledBleu,OUTPUT); // Broche ledBleu configur�e en sortie

// ------- Broches en entr�es num�riques -------  

// ------- Activation si besoin du rappel au + (pullup) des broches en entr�es num�riques -------  

// ------- Initialisation des variables utilis�es -------  

// ------- Codes d'initialisation utile -------  

} // fin de la fonction setup()
// ********************************************************************************

////////////////////////////////// 3. FONCTION LOOP = Boucle sans fin = coeur du programme //////////////////
// la fonction loop() s'ex�cute sans fin en boucle aussi longtemps que l'Arduino est sous tension

void loop(){ // debut de la fonction loop()


//--- attention - avec une LED RGB anode commune : la LED s'allume sur niveau BAS !

//---- vert ---
digitalWrite(ledVert,LOW); // allume la couleur voulue
delay(1000); // pause
digitalWrite(ledVert,HIGH); // �teint la couleur voulue
delay(1000); // pause

//---- rouge ---
digitalWrite(ledRouge,LOW); // allume la couleur voulue
delay(1000); // pause
digitalWrite(ledRouge,HIGH); // �teint la couleur voulue
delay(1000); // pause

//---- bleu ---
digitalWrite(ledBleu,LOW); // allume la couleur voulue
delay(1000); // pause
digitalWrite(ledBleu,HIGH); // �teint la couleur voulue
delay(1000); // pause

//----- test des couleurs au format RVB ---- 

//---- violet --- 
ledRVB(R,0,B); // allume R ouge et Bleu => violet
delay(1000); // pause
ledRVB(0,0,0); // �teint toutes les couleurs
delay(1000); // pause

//---- jaune --- 
ledRVB(R,V,0); // allume R ouge et Vert => jaune
delay(1000); // pause
ledRVB(0,0,0); // �teint toutes les couleurs
delay(1000); // pause

//---- bleu clair --- 
ledRVB(0,V,B); // allume Vert et Bleu => bleu clair
delay(1000); // pause
ledRVB(0,0,0); // �teint toutes les couleurs
delay(1000); // pause

//---- blanc --- 
ledRVB(R,V,B); // allume Rouge Vert et Bleu => blanc
delay(1000); // pause
ledRVB(0,0,0); // �teint toutes les couleurs
delay(1000); // pause


//----- variation de couleur

// variation de rouge
for (int i=0; i<=255; i++) { // d�file valeur 0 � 255
  ledRVBpwm(i,0,0); // g�n�re impulsion largeur voulue pour la couleur
  delay(10); //pause
}

//ledRVB(0,0,0); // �teint toutes les couleurs

// variation de bleu - rouge d�gressif
for (int i=0; i<=255; i++) { // d�file valeur 0 � 255
  ledRVBpwm(255-i,0,i); // g�n�re impulsion largeur voulue pour la couleur
  delay(10); //pause
}

//ledRVB(0,0,0); // �teint toutes les couleurs

// variation de vert - bleu d�gressif
for (int i=0; i<=255; i++) { // d�file valeur 0 � 255
  ledRVBpwm(0,i,255-i); // g�n�re impulsion largeur voulue pour la couleur
  delay(10); //pause
}

// variation de jaune 
for (int i=0; i<=255; i++) { // d�file valeur 0 � 255
  ledRVBpwm(i,255,0); // g�n�re impulsion largeur voulue pour la couleur
  delay(10); //pause
}

//etc... 

ledRVB(0,0,0); // �teint toutes les couleurs
delay(1000); 

//while(1); // stop loop

} // fin de la fonction loop() - le programme recommence au d�but de la fonction loop sans fin
// ********************************************************************************


// ////////////////////////// FONCTIONS DE GESTION DES INTERRUPTIONS //////////////////// 


// ////////////////////////// AUTRES FONCTIONS DU PROGRAMME //////////////////// 

//---- fonction pour combiner couleurs ON/OFF ---- 

void ledRVB(int Rouge, int Vert, int Bleu) {

  //--- attention - avec une LED RGB anode commune : la LED s'allume sur niveau BAS !

 if (Rouge==1) digitalWrite(ledRouge,LOW); // allume couleur
 if (Rouge==0) digitalWrite(ledRouge,HIGH); // �teint couleur

 if (Vert==1) digitalWrite(ledVert,LOW); // allume couleur
 if (Vert==0) digitalWrite(ledVert,HIGH); // �teint couleur

 if (Bleu==1) digitalWrite(ledBleu,LOW); // allume couleur
 if (Bleu==0) digitalWrite(ledBleu,HIGH); // �teint couleur

}

//---- fonction pour variation progressive des couleurs ---- 

void ledRVBpwm(int pwmRouge, int pwmVert, int pwmBleu) { // re�oit valeur 0-255 par couleur

   //--- attention - avec une LED RGB anode commune : la LED s'allume sur niveau BAS !

 analogWrite(ledRouge, 255-pwmRouge); // impulsion largeur voulue sur la broche 0 = 0% et 255 = 100% haut
 analogWrite(ledVert, 255-pwmVert); // impulsion largeur voulue sur la broche 0 = 0% et 255 = 100% haut
 analogWrite(ledBleu, 255-pwmBleu); // impulsion largeur voulue sur la broche 0 = 0% et 255 = 100% haut


}
// ////////////////////////// Fin du programme //////////////////// 

