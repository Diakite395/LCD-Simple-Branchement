# Fonctionnement et Branchement du LiquidCrystal 16x2 avec Arduino

## Fonctionnement
Le LiquidCrystal 16x2 est un écran LCD capable d'afficher **16 caractères sur 2 lignes**. Il utilise un contrôleur (souvent HD44780) pour communiquer avec une carte Arduino. Cet écran permet d'afficher des caractères alphanumériques et des symboles personnalisés.

### Modes de communication :
1. **Mode 8 bits** : Utilise 8 broches pour transmettre les données (D0 à D7).
2. **Mode 4 bits** (le plus courant) : Utilise seulement 4 broches (D4 à D7) pour économiser des broches sur l'Arduino.

---

## Branchement en Mode 4 Bits

### Matériel nécessaire
- Un écran LCD 16x2.
- Une résistance de **220 Ω** (pour la LED de rétroéclairage).
- Un potentiomètre **10 kΩ** (pour régler le contraste).
- Des fils de connexion.
- Une plaque de prototypage (breadboard).

### Schéma des connexions

| **Broche LCD** | **Description**             | **Connexion avec Arduino** |
|-----------------|-----------------------------|-----------------------------|
| 1 (GND)         | Masse                      | GND                        |
| 2 (VDD)         | Alimentation               | 5V                         |
| 3 (VO)          | Contraste                  | Curseur du potentiomètre   |
| 4 (RS)          | Sélection commande/donnée  | Broche numérique 12        |
| 5 (RW)          | Lecture/Écriture           | GND (pour mode écriture)   |
| 6 (EN)          | Enable                     | Broche numérique 11        |
| 11 (D4)         | Donnée 4 bits              | Broche numérique 5         |
| 12 (D5)         | Donnée 4 bits              | Broche numérique 4         |
| 13 (D6)         | Donnée 4 bits              | Broche numérique 3         |
| 14 (D7)         | Donnée 4 bits              | Broche numérique 2         |
| 15 (LED+)       | Rétroéclairage (Anode)     | 5V via une résistance de 220 Ω |
| 16 (LED-)       | Rétroéclairage (Cathode)   | GND                        |

### Potentiomètre
- **Borne extérieure 1** : Connectée au **5V** avec une resistance de **220 Ω**.
- **Borne extérieure 2** : Connectée au **GND**.
- **Borne centrale** : Connectée à la broche **VO** du LCD (pour régler le contraste).

---
## Voici deux images, une avec rétroéclairage et l'autre sans rétroéclairage

### Avec rétroéclairage
![image avec rétroéclairage](https://github.com/Diakite395/LCD-Simple-Branchement/blob/main/r%C3%A9tro%C3%A9clairage.png)

### Sans rétroéclairage
![image avec rétroéclairage](https://github.com/Diakite395/LCD-Simple-Branchement/blob/main/sans%20r%C3%A9tro%C3%A9clairage.png)

## Exemple de Code Arduino

Voici un exemple simple pour afficher un message sur l'écran LCD :

```cpp
#include <LiquidCrystal.h>

// Initialisation des broches RS, EN, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Configuration de l'écran LCD
  lcd.begin(16, 2);
  
  // Affichage d'un message
  lcd.print("Bonjour !");
}

void loop() {
  // Déplacement du texte sur la 2e ligne
  lcd.setCursor(0, 1);
  lcd.print("Arduino LCD");
  delay(1000);
}
