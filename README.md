# Runner 2D - Projet

## "Trust me, I'm Not A Witch!"

### Introduction
- Titre du jeu : *Trust me, I'm not a witch!*
- Genre : Runner / Plateformer 2D
- Plateforme : PC
- Contrôles : Clavier / Souris / Manette
- Mécanique principale : Déplacement horizontal (vers la droite), fuite permanente face à une menace venant de la gauche.
- Direction artistique / Histoire : Fantaisie médiévale humoristique et magique.
- Moteur / Langage : SFML 3.0.0, C++ (Visual Studio 2022)

### Description : 
Le joueur incarne **Notta**, une jeune sorcière accusée à tort, poursuivie par des paysans en colère.
Elle devra fuir à travers divers environnements remplis de pièges, d’obstacles et d’ennemis.
Grâce à ses pouvoirs magiques, Notta peut sauter, glisser, tirer des projectiles et utiliser son agilité pour survivre le plus longtemps possible.

## Contrôles :
### Clavier Souris :
- Q permet de ralentir la vitesse de Notta.
- S permet de glisser (slide).
- Spacebar : Saut
- Souris : Permet de controller des tirs que Notta utilisera pour détruire des obstacles et éliminer les ennemis

## Mécaniques :
- Le joueur sera obligé de se déplacer vers la droite afin de ne pas perdre la partie: si les paysans rattrappe Notta, alors un écran de game over s'affichera.
- La carte sera généré procéduralement pour donner un effet infini et répétitif sans pour autant être ennuyeux.
- Le joueur aura la capacité de tirer des projectiles sur des obstacles pour les détruire si ceux-ci bloquent le chemin. 
- Un système d'inertie et de vélocité permettra au joueur de ressentir la vitesse de Notta.
- La vitesse du joueur augmente avec le temps, ce qui rend les parties longues plus difficiles.

## Objectifs Techniques
- Implémentation d’un système de collision entre le joueur, le sol et les obstacles.
- Utilisation d’un gestionnaire d’entités (player, ennemis, projectiles, power-ups).
- Création d’un système d’animations dynamique à partir de spritesheets.
- Gestion de la caméra, du scrolling, et de l’arrière-plan parallaxe.
- Organisation du projet via Visual Studio filters et GitHub pour le travail collaboratif.

## Moteur de jeu :
Utilisation de SFML 3.0.0, codé avec C++ sur Visual Studio 2022.

## Histoire et direction artistique :
Le jeu adopte une esthétique **cartoon et colorée**, inspirée des RPGs de fantaisie et des dessins animés humoristiques.
Les personnages sont volontairement exagérés, et l’univers ne cherche pas la logique mais la comédie.
Chaque élément visuel — ennemis, obstacles, décors — vise à renforcer ce contraste entre le monde « sérieux » des villageois et la nature maladroitement innocente de Notta.

## Améliorations Futures
- Menu principal et options de personnalisation.
- Plus de sorts et de power-ups.
- Ennemis supplémentaires avec comportements variés.
- Optimisation de la génération procédurale.
