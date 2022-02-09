/*
 * Projet VIC by AMBYSTHO
 * Authors :  POURCHER Franck
 *            FERNANDES Axel
 *            SOMME Francois-Xavier
 *            PEREIRA Lucas
 *            DEMAZURE Martin
 */

//###########################################################################################################################################
//##                                                             DEFINE
//###########################################################################################################################################
 
//#########  Librairies  ###########
#include <stdint.h>
#include <LCD.h>
#include <SPI.h>
#define __AVR_ATmega32U4__
#include <SoftwareSerial.h>

//#########  Version  ###########
#define VERSION 0.0.1

//#########  Parametre d'affichage  ###########
//Nombre max de module
#define MAX_AFFICHAGE 50 
//Nombre de ligne du terminal
#define NB_LIGNE_TERMINAL 15 

//#########  MODE DEBUG  ###########
// Mode debug : sortie des erreurs enable
# define DEBUG_MODE true
#if DEBUG_MODE
  #define DEBUG Serial.println
#else
  #define DEBUG //
#endif

//#########  Liste des couleurs  ###########
#define ALICEBLUE             0xF7DF 
#define ANTIQUEWHITE          0xFF5A 
#define AQUA                  0x07FF 
#define AQUAMARINE            0x7FFA 
#define AZURE                 0xF7FF 
#define BEIGE                 0xF7BB 
#define BISQUE                0xFF38 
#define BLACK                 0x0000 
#define BLANCHEDALMOND        0xFF59 
#define BLUE                  0x001F 
#define BLUEVIOLET            0x895C 
#define BROWN                 0xA145 
#define BURLYWOOD             0xDDD0 
#define CADETBLUE             0x5CF4 
#define CHARTREUSE            0x7FE0 
#define CHOCOLATE             0xD343 
#define CORAL                 0xFBEA 
#define CORNFLOWERBLUE        0x64BD 
#define CORNSILK              0xFFDB 
#define CRIMSON               0xD8A7 
#define CYAN                  0x07FF 
#define DARKBLUE              0x0011 
#define DARKCYAN              0x0451 
#define DARKGOLDENROD         0xBC21 
#define DARKGRAY              0xAD55 
#define DARKGREEN             0x0320 
#define DARKKHAKI             0xBDAD 
#define DARKMAGENTA           0x8811 
#define DARKOLIVEGREEN        0x5345 
#define DARKORANGE            0xFC60 
#define DARKORCHID            0x9999 
#define DARKRED               0x8800 
#define DARKSALMON            0xECAF 
#define DARKSEAGREEN          0x8DF1 
#define DARKSLATEBLUE         0x49F1 
#define DARKSLATEGRAY         0x2A69 
#define DARKTURQUOISE         0x067A 
#define DARKVIOLET            0x901A 
#define DEEPPINK              0xF8B2 
#define DEEPSKYBLUE           0x05FF 
#define DIMGRAY               0x6B4D 
#define DODGERBLUE            0x1C9F 
#define FIREBRICK             0xB104 
#define FLORALWHITE           0xFFDE 
#define FORESTGREEN           0x2444 
#define FUCHSIA               0xF81F 
#define GAINSBORO             0xDEFB 
#define GHOSTWHITE            0xFFDF 
#define GOLD                  0xFEA0 
#define GOLDENROD             0xDD24 
#define GRAY                  0x8410 
#define GREEN                 0x0400 
#define GREENYELLOW           0xAFE5 
#define HONEYDEW              0xF7FE 
#define HOTPINK               0xFB56 
#define INDIANRED             0xCAEB 
#define INDIGO                0x4810 
#define IVORY                 0xFFFE 
#define KHAKI                 0xF731 
#define LAVENDER              0xE73F 
#define LAVENDERBLUSH         0xFF9E 
#define LAWNGREEN             0x7FE0 
#define LEMONCHIFFON          0xFFD9 
#define LIGHTBLUE             0xAEDC 
#define LIGHTCORAL            0xF410 
#define LIGHTCYAN             0xE7FF 
#define LIGHTGOLDENRODYELLOW  0xFFDA 
#define LIGHTGREEN            0x9772 
#define LIGHTGREY             0xD69A 
#define LIGHTPINK             0xFDB8 
#define LIGHTSALMON           0xFD0F 
#define LIGHTSEAGREEN         0x2595 
#define LIGHTSKYBLUE          0x867F 
#define LIGHTSLATEGRAY        0x7453 
#define LIGHTSTEELBLUE        0xB63B 
#define LIGHTYELLOW           0xFFFC 
#define LIME                  0x07E0 
#define LIMEGREEN             0x3666 
#define LINEN                 0xFF9C 
#define MAGENTA               0xF81F 
#define MAROON                0x8000 
#define MEDIUMAQUAMARINE      0x6675 
#define MEDIUMBLUE            0x0019 
#define MEDIUMORCHID          0xBABA 
#define MEDIUMPURPLE          0x939B 
#define MEDIUMSEAGREEN        0x3D8E 
#define MEDIUMSLATEBLUE       0x7B5D 
#define MEDIUMSPRINGGREEN     0x07D3 
#define MEDIUMTURQUOISE       0x4E99 
#define MEDIUMVIOLETRED       0xC0B0 
#define MIDNIGHTBLUE          0x18CE 
#define MINTCREAM             0xF7FF 
#define MISTYROSE             0xFF3C 
#define MOCCASIN              0xFF36 
#define NAVAJOWHITE           0xFEF5 
#define NAVY                  0x0010 
#define OLDLACE               0xFFBC 
#define OLIVE                 0x8400 
#define OLIVEDRAB             0x6C64 
#define ORANGE                0xFD20 
#define ORANGERED             0xFA20 
#define ORCHID                0xDB9A 
#define PALEGOLDENROD         0xEF55 
#define PALEGREEN             0x9FD3 
#define PALETURQUOISE         0xAF7D 
#define PALEVIOLETRED         0xDB92 
#define PAPAYAWHIP            0xFF7A 
#define PEACHPUFF             0xFED7 
#define PERU                  0xCC27 
#define PINK                  0xFE19 
#define PLUM                  0xDD1B 
#define POWDERBLUE            0xB71C 
#define PURPLE                0x8010 
#define RED                   0xF800 
#define ROSYBROWN             0xBC71 
#define ROYALBLUE             0x435C 
#define SADDLEBROWN           0x8A22 
#define SALMON                0xFC0E 
#define SANDYBROWN            0xF52C 
#define SEAGREEN              0x2C4A 
#define SEASHELL              0xFFBD 
#define SIENNA                0xA285 
#define SILVER                0xC618 
#define SKYBLUE               0x867D 
#define SLATEBLUE             0x6AD9 
#define SLATEGRAY             0x7412 
#define SNOW                  0xFFDF 
#define SPRINGGREEN           0x07EF 
#define STEELBLUE             0x4416 
#define TAN                   0xD5B1 
#define TEAL                  0x0410 
#define THISTLE               0xDDFB 
#define TOMATO                0xFB08 
#define TURQUOISE             0x471A 
#define VIOLET                0xEC1D 
#define WHEAT                 0xF6F6 
#define WHITE                 0xFFFF 
#define WHITESMOKE            0xF7BE 
#define YELLOW                0xFFE0 
#define YELLOWGREEN           0x9E66


//#########  Definitions des modules  ###########
//Liste des types de module
typedef enum {
    None,
    Texte,
    Bouton,
    Rectangle
} Type_module_t;

//Definition d'un module
typedef struct {
    Type_module_t type;
    bool update_a;
    void* pointeur;
} Module_t;

//Definition d'un module de texte
typedef struct {
    int x;
    int y;
    uint8_t *texte;
    uint16_t couleur;
} Texte_t;

//Definition d'un module rectangulaire
typedef struct {
    int x;
    int y;
    int longueur;
    int hauteur;
    uint16_t couleur;
    bool filled;      // fill --> true
} Rect_t;

//Definition d'un module bouton
typedef struct {
    int x;
    int y;
    int longueur;
    int hauteur;
    uint8_t *texte;
    uint16_t couleur_t;
    uint16_t couleur_bg;
} Bouton_t;

//#########  Tableau necessaire à l'affichage  ###########
Module_t Liste_Affichage[MAX_AFFICHAGE];
Texte_t Liste_Texte[MAX_AFFICHAGE];   
Bouton_t Liste_Bouton[MAX_AFFICHAGE];   
Rect_t Liste_Rectangle[MAX_AFFICHAGE]; 

//#########  Definition des fonctions  ###########
//Créateur, Afficheur (Destructeur a faire)

//Bouton
int Creation_MyButton(int x, int y, int decallage, int hauteur, uint8_t *Titre, uint16_t couleur_t, uint16_t couleur_bg);
int Affichage_MyButton(Bouton_t *pointeur);

//Texte
int Creation_MyTexte( int x, int y, uint8_t *texte, uint16_t couleur);
int Affichage_MyTexte(Texte_t *pointeur);

//Rectangle
int Creation_MyRectangle( int x, int y, int decallage, int hauteur, uint16_t couleur, bool filled);
int Affichage_Myrectangle(Texte_t *pointeur);


//#########  Parametre BLUETOOTH  ###########
SoftwareSerial BTserial(15,14);  //old(17, 16); // RX | TX
const long baudRate = 9600;//38400; 

//#########  Variables Globales  ###########
char c=' ';
char Tx[20], Rx[20];
boolean NL = true;

uint16_t color_bg;
bool Changement_Affichage;
uint8_t* tab_terminal[NB_LIGNE_TERMINAL];
int ligne=0, charactere=0, curseur=0, tx=0, rx=0;


//Fonction rapide pour les besoin de la DEMO
int clear_terminal()
{
  curseur=0;
  for (int i = 0; i <= NB_LIGNE_TERMINAL; i++)
  {
    tab_terminal[i]=(const uint8_t *)" ";
  }
}

//###########################################################################################################################################
//##                                                             SETUP
//###########################################################################################################################################
void setup()
{
    /////////////////////////////////////////////////////////////////////////////////////////////
    //                                      INIT SERIAL
    /////////////////////////////////////////////////////////////////////////////////////////////
    Serial.begin(9600);
    //Serial.print("Sketch:   ");
    //Serial.println(FILE);
    //Serial.print("Uploaded: ");
    //Serial.println(DATE);
    //Serial.println(" ");

    
    /////////////////////////////////////////////////////////////////////////////////////////////
    //                                      INIT BLUETOOTH
    /////////////////////////////////////////////////////////////////////////////////////////////
    BTserial.begin(baudRate);
    Serial.print("BTserial started at "); Serial.println(baudRate);
    Serial.println(" "); 
    

    /////////////////////////////////////////////////////////////////////////////////////////////
    //                                         INIT LCD
    /////////////////////////////////////////////////////////////////////////////////////////////    
    SPI.setDataMode(SPI_MODE3);
    SPI.setBitOrder(MSBFIRST);
    SPI.setClockDivider(SPI_CLOCK_DIV4);
    SPI.begin();
    
    Tft.lcd_init();                                      // init TFT library

    
    Tft.lcd_display_string(50, 150, (const uint8_t *)"INITIALIZING...", FONT_1608, RED);

    //delay(2000);




    /////////////////////////////////////////////////////////////////////////////////////////////
    //                                       INIT AFFICHAGE
    /////////////////////////////////////////////////////////////////////////////////////////////

    for (int i = 0; i <= MAX_AFFICHAGE; i++)
    {
      Liste_Affichage[i].type  = None;
      Liste_Texte[i].texte     = (const uint8_t *)"";
      Liste_Bouton[i].texte    = (const uint8_t *)"";
      Liste_Rectangle[i].x     = -1;
    }


  
    /////////////////////////////////////////////////////////////////////////////////////////////
    //                                       INIT DEMO
    /////////////////////////////////////////////////////////////////////////////////////////////
    color_bg=DARKBLUE;
    
    //fond
    //Tft.lcd_fill_rect(0, 0, 250, 350, color_bg);
    if (Creation_MyRectangle(0, 0, 250, 350, color_bg, true) >= 0) DEBUG("/!\ ERROR : Echec Creation fond");

    if (Creation_MyButton(50, 250, 140, 50, (const uint8_t *)"Clean", SANDYBROWN, GRAY) > 0) DEBUG("/!\ ERROR : Echec Creation bouton clear");
    if (Creation_MyRectangle(20, 50, 200, 190, BLACK, true) >= 0) DEBUG("/!\ ERROR : Echec Creation fond terminal");
    if (Creation_MyRectangle(20, 50, 200, 190, WHITE, false) >= 0) DEBUG("/!\ ERROR : Echec Creation tour terminal");

    for (int i = 0; i <= NB_LIGNE_TERMINAL; i++)
    {
      tab_terminal[i]=(const uint8_t *)"test";//source erreur pointeur ?
      if (Creation_MyTexte( 25, 54+11*i, tab_terminal[i], GOLD) >= 0) DEBUG("/!\ ERROR : Echec Creation ligne terminal");
    }

    if (Creation_MyTexte( 20, 20, (const uint8_t *)"VIC by Ambysto - V0.0.1", ALICEBLUE) >= 0) DEBUG("/!\ ERROR : Echec Creation titre");
    curseur=0;
}


//###########################################################################################################################################
//##                                                             LOOP
//###########################################################################################################################################
void loop()
{
    Serial.flush();

    
    /////////////////////////////////////////////////////////////////////////////////////////////
    //                                       RECEPTION
    /////////////////////////////////////////////////////////////////////////////////////////////
    // Read from the Bluetooth module and send to the Arduino Serial Monitor
    //if (Serial.available())
    while(BTserial.available())
    {
        c = BTserial.read();
        Serial.write(c);
        //c = Serial.read();
        Tx[tx]=c;
        tx++;
        
        if(tx>1)
        {
          DEBUG("tx > 1");
          if(c==(char(10)))//if(Tx[tx] == '/' and Tx[tx-1] == '0')
          {
            DEBUG("mot complet");
            tx=0;
            if(curseur >= NB_LIGNE_TERMINAL-1)
            {
                DEBUG("terminal full");
                for(int i=0; i <= NB_LIGNE_TERMINAL-1; i++)
                {
                  tab_terminal[i]=tab_terminal[i+1];
                }
                tab_terminal[curseur]=Tx;
            }else
            {
              tab_terminal[curseur]=Tx;
              curseur++;
              DEBUG("curseur +1");
            }
            
            //tab_terminal[curseur]=Tx;
            DEBUG(Tx);
            for (int i = 0; i <= NB_LIGNE_TERMINAL; i++)
            {
              Liste_Texte[i].texte=(const uint8_t *)tab_terminal[i];
              Liste_Affichage[i+5].update_a=true;

               
            }
            Changement_Affichage=true;
          }
        }
    }
 

    /////////////////////////////////////////////////////////////////////////////////////////////
    //                                       EMISSION
    /////////////////////////////////////////////////////////////////////////////////////////////
    // Read from the Serial Monitor and send to the Bluetooth module
    while(Serial.available())
    {
        c = Serial.read();
        BTserial.write(c);
    }


    /////////////////////////////////////////////////////////////////////////////////////////////
    //                                       AFFICHAGE
    /////////////////////////////////////////////////////////////////////////////////////////////  
    if (Affichage()) DEBUG("/!\ERROR : Echec Affichage !");

    delay(500);
}






//###########################################################################################################################################
//##                                                             FONCTIONS
//###########################################################################################################################################


/////////////////////////////////////////////////////////////////////////////////////////////
//                                       AFFICHAGE
/////////////////////////////////////////////////////////////////////////////////////////////  
//lit la liste et lance la fonction adéquate
int Affichage()
{
  if(true) //Changement_Affichage)//en cours de transformation
  {
    for (int i = 0; i <= MAX_AFFICHAGE; i++) 
    {
      if(Liste_Affichage[i].update_a == true)
      {
        Liste_Affichage[i].update_a = false;
        switch(Liste_Affichage[i].type)
        {
          case Texte:
            Affichage_MyTexte(Liste_Affichage[i].pointeur);
            break;
          case Bouton:
            Affichage_MyButton(Liste_Affichage[i].pointeur);
            break;
          case Rectangle:
            Affichage_MyRectangle(Liste_Affichage[i].pointeur);
            break;
          default:
            
            break;
        }
      }
      Changement_Affichage=false;
    }
  }

  return 0;
}


//retire et détruit un module de la liste d'affichage
int Destruct_module(int n)
{
  switch(Liste_Affichage[n].type)
  {
    case Texte:
      Destruct_MyTexte(Liste_Affichage[n].pointeur);
      break;
    case Bouton:
      Destruct_MyButton(Liste_Affichage[n].pointeur);
      break;
    case Rectangle:
      Destruct_MyRectangle(Liste_Affichage[n].pointeur);
      break;
    default:
      
      break;
  }
  Liste_Affichage[n].type=None;
  Changement_Affichage=true;
}



////////////////////////////TEXTE/////////////////////////////////

//ajoute le texte à la liste
int Creation_MyTexte( int x, int y, uint8_t *texte, uint16_t couleur)
{
  int n=0, m=0;
  Changement_Affichage=true;
  
  while(m<MAX_AFFICHAGE and Liste_Texte[m].texte != "")m++;
  if (m >= MAX_AFFICHAGE)
  {
    DEBUG("/!\ ERROR : Liste_Texte plein !");
    return -1;
  }
  Liste_Texte[m].x=x;
  Liste_Texte[m].y=y;
  Liste_Texte[m].texte=texte;
  Liste_Texte[m].couleur=couleur;
  
  while(n<MAX_AFFICHAGE and Liste_Affichage[n].type != None)n++;
  if (n >= MAX_AFFICHAGE)
  {
    DEBUG("/!\ ERROR : Liste_Affichage plein !");
    return -2;
  }
  Liste_Affichage[n].type=Texte;
  Liste_Affichage[n].update_a=true;
  Liste_Affichage[n].pointeur=&Liste_Texte[m];
  return n;
}



//affiche un texte
int Affichage_MyTexte(Texte_t *pointeur)
{
  Texte_t text = *pointeur;
  Tft.lcd_display_string(text.x, text.y, text.texte, FONT_1608, text.couleur);
  return 0;
}



//detruit un texte
int Destruct_MyTexte(Texte_t *pointeur)
{
  pointeur->texte="";
  return 0;
}




///////////////////://///////BOUTON////////////////////////////////

//ajoute le bouton à la liste
int Creation_MyButton(int x, int y, int decallage, int hauteur, uint8_t * Titre, uint16_t couleur_t, uint16_t couleur_bg)
{
  int n=0, m=0;
  Changement_Affichage=true;
  
  while(m<MAX_AFFICHAGE and Liste_Bouton[m].texte != (const uint8_t *)"")m++;
  if (m >= MAX_AFFICHAGE)
  {
    DEBUG("/!\ ERROR : Liste_Bouton plein !");
    return -1;
  }
  Liste_Bouton[m].x=x;
  Liste_Bouton[m].y=y;
  Liste_Bouton[m].longueur=decallage;
  Liste_Bouton[m].hauteur=hauteur;
  Liste_Bouton[m].texte=Titre;
  Liste_Bouton[m].couleur_t=couleur_t;
  Liste_Bouton[m].couleur_bg=couleur_bg;
  
  while(n<MAX_AFFICHAGE and Liste_Affichage[n].type != None)n++;
  if (n >= MAX_AFFICHAGE)
  {
    DEBUG("/!\ ERROR : Liste_Affichage plein !");
    return -2;
  }
  Liste_Affichage[n].type=Bouton;
  Liste_Affichage[n].update_a=true;
  Liste_Affichage[n].pointeur=&Liste_Bouton[m];
  return n;
}



//affiche un bouton
int Affichage_MyButton(Bouton_t *pointeur)
{
  Bouton_t button = *pointeur;
  Tft.lcd_draw_rect(button.x-1, button.y-5, button.longueur+1, button.hauteur+5, WHITE);
  Tft.lcd_fill_rect(button.x-1, button.y-5, button.longueur+1, button.hauteur+5, button.couleur_bg);
  Tft.lcd_display_string(button.x+50, button.y+15, button.texte, FONT_1608,button.couleur_t);
  return 0;
}  



//detruit un bouton
int Destruct_MyButton(Bouton_t *pointeur)
{
  pointeur->texte="";
  return 0;
}




/////////////////////////////RECTANGLE////////////////////////////////

//ajoute le rectangle à la liste
int Creation_MyRectangle(int x, int y, int decallage, int hauteur, uint16_t couleur, bool filled)
{
  int n=0, m=0;
  Changement_Affichage=true;
  
  while(m<MAX_AFFICHAGE and Liste_Rectangle[m].x != -1)m++;
  if (m >= MAX_AFFICHAGE)
  {
    DEBUG("/!\ ERROR : Liste_Rectangle plein !");
    return -1;
  }
  Liste_Rectangle[m].x=x;
  Liste_Rectangle[m].y=y;
  Liste_Rectangle[m].longueur=decallage;
  Liste_Rectangle[m].hauteur=hauteur;
  Liste_Rectangle[m].couleur=couleur;
  Liste_Rectangle[m].filled=filled;
  
  while(n<MAX_AFFICHAGE and Liste_Affichage[n].type != None)n++;
  if (n >= MAX_AFFICHAGE)
  {
    DEBUG("/!\ ERROR : Liste_Affichage plein !");
    return -2;
  }
  Liste_Affichage[n].type=Rectangle;
  Liste_Affichage[n].update_a=true;
  Liste_Affichage[n].pointeur=&Liste_Rectangle[m];
  return n;
}


//affiche un rectangle
int Affichage_MyRectangle(Rect_t *pointeur)
{
  Rect_t rectangle = *pointeur;
  if(rectangle.filled)
  {
    Tft.lcd_fill_rect(rectangle.x, rectangle.y, rectangle.longueur, rectangle.hauteur, rectangle.couleur);

  }else
  {
    Tft.lcd_draw_rect(rectangle.x, rectangle.y, rectangle.longueur, rectangle.hauteur, rectangle.couleur);
  }
  return 0;
} 


//detruit un rectangle
int Destruct_MyRectangle(Rect_t *pointeur)
{
  pointeur->x=-1;
  return 0;
}



/////////////////////////////////////////////////////////////////////////////////////////////
//                        Liste des fonction de la librairie LCD
/////////////////////////////////////////////////////////////////////////////////////////////  
/* fonction librairie LCD
 *  lcd_init()
 *  lcd_draw_point(uint16_t hwXpos, uint16_t hwYpos, uint16_t hwColor) 
 *  lcd_display_char(uint16_t /*hwXpos*_/hwYpos, //specify x position.
              uint16_t /*hwYpos*_/hwXpos, //specify y position.
              uint8_t chChr,   //a char is display.
              uint8_t chSize,  //specify the size of the char
              uint16_t hwColor) //specify the color of the char
 *  lcd_display_num(uint16_t hwXpos,  //specify x position.
              uint16_t hwYpos, //specify y position.
              uint32_t chNum,  //a number is display.
              uint8_t chLen,   //length ot the number
              uint8_t chSize,  //specify the size of the number
              uint16_t hwColor) //specify the color of the number
 *  lcd_display_string(uint16_t hwXpos, //specify x position.
              uint16_t hwYpos,   //specify y position.
              const uint8_t *pchString,  //a pointer to string
              uint8_t chSize,    // the size of the string 
              uint16_t hwColor)  // specify the color of the string 
 *  lcd_draw_line(uint16_t hwXpos0, //specify x0 position.
              uint16_t hwYpos0, //specify y0 position.
              uint16_t hwXpos1, //specify x1 position.
              uint16_t hwYpos1, //specify y1 position.
              uint16_t hwColor) //specify the color of the line
 *  lcd_draw_circle(uint16_t hwXpos,  //specify x position.
              uint16_t hwYpos,  //specify y position.
              uint16_t hwRadius, //specify the radius of the circle.
              uint16_t hwColor)  //specify the color of the circle.
 *  lcd_fill_rect(uint16_t hwXpos,  //specify x position.
              uint16_t hwYpos,  //specify y position.
              uint16_t hwWidth, //specify the width of the rectangle.
              uint16_t hwHeight, //specify the height of the rectangle.
              uint16_t hwColor)  //specify the color of rectangle.
 *  lcd_draw_v_line(uint16_t hwXpos, //specify x position.
              uint16_t hwYpos, //specify y position. 
              uint16_t hwHeight, //specify the height of the vertical line.
              uint16_t hwColor)  //specify the color of the vertical line.
 *  lcd_draw_h_line(uint16_t hwXpos, //specify x position.
              uint16_t hwYpos,  //specify y position. 
              uint16_t hwWidth, //specify the width of the horizonal line.
              uint16_t hwColor) //specify the color of the horizonal line.
 *  lcd_draw_rect(uint16_t hwXpos,  //specify x position.
              uint16_t hwYpos,  //specify y position.
              uint16_t hwWidth, //specify the width of the rectangle.
              uint16_t hwHeight, //specify the height of the rectangle.
              uint16_t hwColor)  //specify the color of rectangle.
*/
