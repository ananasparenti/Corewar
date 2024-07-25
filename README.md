# Corewar 🔨
[![forthebadge](http://forthebadge.com/images/badges/powered-by-electricity.svg)](http://forthebadge.com)

Qu'est ce que un Corewar ? Simplement, il s'agit d'une arène dans laquelle peuvent se battre 2 à 4 champions. Chacun a un cycle de vie ainsi que des attaques à effectuer chacun leur tour.

### Pré-requis 📌
- Avoir cloner le repository.

### Mise en place 🙌
- Cloner le depôt avec la commande ``git clone`` + la clé SSH (sous Linux) ou l'URL (sous Windows).

### Comment l'utiliser ? ⚙️
- En utilisant le makefile, compiler le projet avec la commande ``make``.
- Puis lancer le programme avec ``./corewar`` + au moins 2 champions tel que ``champions/abel.cor`` ou encore ``champions/live.cor``

Les différents flags utilisables:
- ``-a``, pour choisir l'adresse de où va partir le robot.

    _exemple :_ ``./corewar -a 4 champions /abel.cor -a 6 champions/live.cor``

- ``-n``, pour donner un id aux champions.
  
    _exemple :_ ``./corewar -n 4 champions /abel.cor -n 6 champions/live.cor``
- ``-dump``, pour afficher l'arène en temps réel.
- 
  _exemple :_ ``./corewar champions /abel.cor champions/live.cor -dump``

### Fabriqué avec 💡
* [VsCode](https://code.visualstudio.com/) - Visual Studio Code

### Auteures
* **Sara Himmich** _alias_ [@sara.himmich@epitech.eu](https://github.com/Sara28himmich)
* **Anaïs Parenti** _alias_ [@anais.parenti@epitech.eu](https://github.com/ananasparenti)

