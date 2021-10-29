## 
Kopplingsdäckets storlek ska kunnas sättas i runtime
Kopplingsdäckets hål har kontakt vertikalt
Kopplingsdäcket ska kunna visas visuellt i terminalen med komponenterna på plats

Man ska kunna placera ut resistorer på däcket horisontellt, endast en komponent per hål, komponenterna får inte överlappa
Man ska kunna ta bort komponenter


Man ska kunna kontollera om två pungter har kontakt


Man ska kunna spara och läsa in kopplingsdäcket, med alla komponenter, till/från en fil
Man ska kunna få ut den totala resistansen mellan två punkter

##

./cboard sparad-kd-fil <- starta programmet med det sparade kopplingsdäcket 
./cboard 32 <- starta programmet med ett nytt kopplingsdäck med storleken 32x32
./cboard 14 34 <- starta programmet med ett nytt kopplingsdäck med storleken 14x34 
./cboard
"Size for breadboard: "

##

"""
What would you like to do?
1: Place resistor
2: Remove resistor
3: Test connection between points
4: Measure resistance
5: Save to file
0: Quit
"""

##

int BreadboardPlaceResistor(Breadboard*, Resistor)
	if resistor is not obstructed, add resistor to breadboard

int BreadboardIsObstructed(Breadboard*, Resistor) 
	if range in row is not obstructed(found in a resistor(struct))

int BreadboardRemoveResistor(Breadboard*, Point)
	if resistor at point, remove from breadboard

int BreadboardIsConnected(Breadboard*, col1, col2)
	

Point { x y }
Range { row start end }
Resistor { Range value }






