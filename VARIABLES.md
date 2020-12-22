#OS

Si vous souhaitez contribuer au code, ou bien juste le comprendre, une certaine convention au niveau du nommage variables est nécessaire.
C'est pourquoi nous avons définit les normes suivantes :

Les variable simples sont notées : ma_variable
Les fonctions : maFonction
Les nom de structures (dans les typedef) : MaStructure
Les variables provenant de structures : Ma_Variable
Les define (de constantes) : MA_DEFINITION
Les variables systèmes : On rajoute un "_" devant le nom de la variable, par exemple:
     Structure : _MaStructure
     Variable : _ma_var
     Variable provenant d'une structure : _Ma_Var
     Fonctions (appels systèmes et interruptions) : _maFonction

Les macros assembleurs se nomme de la même manière que les définitions en C.
Les définitions internes de structures, de variables et de fonctions (donc celles que l'utilisateur n'est pas sensé utiliser)
ont un _ en plus à la fin:
	Structure : MaStructure_
    Variable : ma_var_
    Variable provenant d'une structure : Ma_Var_
    Fonctions (appels systèmes et interruptions) : maFonction_

Certaines fois, les noms de variables structurées et de structures peuvent être similaires (cas des variables avec un seul mot). A ce moment, 
nommer la variable structurée comme une variable normale.

NB: Les développeurs sont priés de se tenir à ces normes. Si vous avez des suggestions concernant le nommage des variables, vous êtes priés
d'envoyer un mail à "newos2345@gmail.com" .
