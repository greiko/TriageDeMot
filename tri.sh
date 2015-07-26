#!/bin/bash
RED='\033[0;31m'
NC='\033[0m' # No Color
echo -e "${RED}Creation de fichiers ${NC}"
make
mkdir tests_resultats
echo -e "${RED}------------------------------------------------------------------${NC}"
echo -e "${RED}Test 1 ${NC}"
./tri tests_fonctionnels/1.txt -S tests_resultats/stats1.txt > tests_resultats/resultat_1.txt
diff tests_fonctionnels/stats1.txt tests_resultats/stats1.txt
diff tests_fonctionnels/attendu_1.txt tests_resultats/resultat_1.txt
echo -e "${RED}------------------------------------------------------------------${NC}"
echo -e "${RED}Test 2 ${NC}"
./tri tests_fonctionnels/2.txt -S tests_resultats/stats2.txt > tests_resultats/resultat_2.txt
diff tests_fonctionnels/stats2.txt tests_resultats/stats2.txt
diff tests_fonctionnels/attendu_2.txt tests_resultats/resultat_2.txt
echo -e "${RED}------------------------------------------------------------------${NC}"
echo -e "${RED}Test 3 ${NC}"
./tri tests_fonctionnels/3.txt -S tests_resultats/stats3.txt > tests_resultats/resultat_3.txt
diff tests_fonctionnels/stats3.txt tests_resultats/stats3.txt
diff tests_fonctionnels/attendu_3.txt tests_resultats/resultat_3.txt
echo -e "${RED}------------------------------------------------------------------${NC}"
echo -e "${RED}Test 4 ${NC}"
./tri tests_fonctionnels/4.txt -S tests_resultats/stats4.txt > tests_resultats/resultat_4.txt
diff tests_fonctionnels/stats4.txt tests_resultats/stats4.txt
diff tests_fonctionnels/attendu_4.txt tests_resultats/resultat_4.txt
echo -e "${RED}------------------------------------------------------------------${NC}"
echo -e "${RED}Test 5: cest plein despace et de retour de ligne nowhere ${NC}"
./tri tests_fonctionnels/5.txt -S tests_resultats/stats5.txt > tests_resultats/resultat_5.txt
diff tests_fonctionnels/stats5.txt tests_resultats/stats5.txt
diff tests_fonctionnels/attendu_5.txt tests_resultats/resultat_5.txt
echo -e "${RED}------------------------------------------------------------------${NC}"
echo -e "${RED}Test Alphabet ${NC}"
./tri tests_fonctionnels/alpha.txt -S tests_resultats/statsalpha.txt > tests_resultats/resultat_alpha.txt
diff tests_fonctionnels/statsalpha.txt tests_resultats/statsalpha.txt
diff tests_fonctionnels/attendu_alpha.txt tests_resultats/resultat_alpha.txt
echo -e "${RED}------------------------------------------------------------------${NC}"
echo -e "${RED}Test NO FILE ${NC}"
./tri tests_fonctionnels/noWord.txt -S tests_resultats/statsnoWord.txt > tests_resultats/resultat_noWord.txt
diff tests_fonctionnels/attendu_noWord tests_resultats/resultat_noWord.txt
echo -e "${RED}------------------------------------------------------------------${NC}"
echo -e "${RED}Test One Line ${NC}"
./tri tests_fonctionnels/oneLine.txt -S tests_resultats/statsoneLine.txt > tests_resultats/resultat_oneLine.txt
diff tests_fonctionnels/statsoneLine.txt tests_resultats/statsoneLine.txt
diff tests_fonctionnels/attendu_oneLine.txt tests_resultats/resultat_oneLine.txt
echo -e "${RED}------------------------------------------------------------------${NC}"
echo -e "${RED}Test Two Lines ${NC}"
./tri tests_fonctionnels/retourLigne.txt -S tests_resultats/statsretourLigne.txt > tests_resultats/resultat_retourLigne.txt
diff tests_fonctionnels/statsretourLigne.txt tests_resultats/statsretourLigne.txt
diff tests_fonctionnels/attendu_retourLigne.txt tests_resultats/resultat_retourLigne.txt
echo -e "${RED}------------------------------------------------------------------${NC}"
echo -e "${RED}Test Five Line ${NC}"
./tri tests_fonctionnels/fiveline.txt -S tests_resultats/statsfiveline.txt > tests_resultats/resultat_fiveline.txt
diff tests_fonctionnels/statsfiveline.txt tests_resultats/statsfiveline.txt
diff tests_fonctionnels/attendu_fiveline.txt tests_resultats/resultat_fiveline.txt
echo -e "${RED}------------------------------------------------------------------${NC}"
echo -e "${RED}Test one word ten lines${NC}"
./tri tests_fonctionnels/oneWordTenLines.txt -S tests_resultats/statsonewordtenlines.txt > tests_resultats/resultat_onewordtenlines.txt
diff tests_fonctionnels/statsoneWordTenLines.txt tests_resultats/statsonewordtenlines.txt
diff tests_fonctionnels/attendu_onewordtenlines.txt tests_resultats/resultat_onewordtenlines.txt
echo -e "${RED}------------------------------------------------------------------${NC}"
echo -e "${RED}Clean up de fichiers${NC}"
rm -rf tests_resultats
make clean
echo -e "${RED}------------------------------------------------------------------${NC}"
echo "FIN"
