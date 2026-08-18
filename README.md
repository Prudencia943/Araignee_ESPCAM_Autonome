#  Robot Araignée ESP32

Robot quadrupède autonome construit avec un ESP32, capable de se déplacer, 
d'éviter les obstacles et de détecter une présence via une caméra embarquée.

> Un robot qui se déplace tout seul, évite les obstacles, et détecte une présence.

##  Contexte

Projet réalisé dans le cadre d'un stage à Polytechnique de Douala (Data Science & IA),
en équipe de trois personnes.

##  Fonctionnalités

-  Marche autonome (démarche tripode, 4 pattes / 8 servomoteurs)
-  Évitement d'obstacles (capteur ultrason HC-SR04)
- Sécurité anti-basculement (centrale inertielle MPU6050)
-  Vision embarquée et détection de présence (ESP32-CAM)

##  Matériel utilisé

| Composant | Rôle |
|---|---|
| ESP32 (carte d'extension) | Cerveau principal |
| 8 servomoteurs SG90 | Actionneurs des pattes (Coxa + Fémur) |
| HC-SR04 | Détection d'obstacles |
| MPU6050 | Centrale inertielle |
| ESP32-CAM | Vision et détection de présence |
| Châssis carton ondulé (6mm) | Structure du robot |

##  État d'avancement

-  Logique de marche validée en simulation (Wokwi)
-  Centrage et calibration des servomoteurs
- Marche complète des 4 pattes sur le châssis assemblé
-  Intégration de la détection de présence (ESP32-CAM)

## Auteurs

-NOUMEDEM-MEGNIKENG-NERGE
-FOUODJI TAKO PRUDENCIA
-NGOOH EMMANUEL DYLAN
