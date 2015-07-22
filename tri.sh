#!/bin/bash
RED='\033[0;31m'
NC='\033[0m' # No Color
echo -e "${RED}Creation de fichiers ${NC}"
make
mkdir tests_resultats

echo -e "${RED}Test 1 ${NC}"
./tri tests_fonctionnels/1.txt -S tests_resultats/stats1.txt > tests_resultats/resultat_1.txt
diff tests_fonctionnels/stats1.txt tests_resultats/stats1.txt
diff tests_fonctionnels/attendu_1.txt tests_resultats/resultat_1.txt

echo -e "${RED}Test 2 ${NC}"
./tri tests_fonctionnels/2.txt -S tests_resultats/stats2.txt > tests_resultats/resultat_2.txt
diff tests_fonctionnels/stats2.txt tests_resultats/stats2.txt
diff tests_fonctionnels/attendu_2.txt tests_resultats/resultat_2.txt

echo -e "${RED}Test 3 ${NC}"
./tri tests_fonctionnels/3.txt -S tests_resultats/stats3.txt > tests_resultats/resultat_3.txt
diff tests_fonctionnels/stats3.txt tests_resultats/stats3.txt
diff tests_fonctionnels/attendu_3.txt tests_resultats/resultat_3.txt

echo -e "${RED}Test 4 ${NC}"
./tri tests_fonctionnels/4.txt -S tests_resultats/stats4.txt > tests_resultats/resultat_4.txt
diff tests_fonctionnels/stats4.txt tests_resultats/stats4.txt
diff tests_fonctionnels/attendu_4.txt tests_resultats/resultat_4.txt

echo -e "${RED}Clean up de fichiers${NC}"
rm -rf tests_resultats
make clean

echo "FIN"
