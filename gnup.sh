#!/usr/bin/gnuplot

# Tracer une courbe de température en fonction de l'heure
plot 'results.csv' using 1:2

# Ajouter des titres aux axes et au graphique
set xlabel 'Heure'
set ylabel 'Température (°C)'
set title 'Température au cours de la journée'

# Définir l'étendue de l'axe des ordonnées sur une plage de températures spécifique
set yrange [20:30]

# Enregistrer le graphique dans un fichier image au format PNG
set terminal png
set output 'temperature.png'

# Exécuter la commande de tracé
replot