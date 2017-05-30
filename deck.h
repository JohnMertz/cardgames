#include <stdio.h>
/* Functions:
 *
 * drawCard:
 *     (int number: value of card 1-13
 *      int suit: 0 = Clubs, 1 = Diamonds, 2 = Hearts, 3 = Spades
 *      int widthStart: left edge of card
 *      int widthStop: right edge of card
 *      int heightStart: top edge of card
 *      int heightStop: bottom edge of card
 *     )
 *
 * drawHandFaceUp: 
 *     (int hand[13]: array of cards to print; 4-56, ace: 4-7 (suits above)...
 *      int cardsLeft: number of cards to print
 *      int heightStart: top edge of cards
 *      int heightStop: bottom edge of cards
 *      int width: total width of entire hand (card width calculated automatically)
 *      )
 *
 * drawHandFaceDown: 
 *     (int design: selection of back designs, 0-3, see deck[x] below
 *      int cardsLeft: number of cards to print
 *      int heightStart: top edge of cards
 *      int heightStop: bottom edge of cards
 *      int width: total width of entire hand (card width calculated automatically)
 *      )
 */

char deck[56][12][13]={
    {
        " ___________ ",
        "/           \\",
        "|           |",
        "|           |",
        "|           |",
        "|           |",
        "|           |",
        "|           |",
        "|           |",
        "|           |",
        "|           |",
        "\\___________/"
    },{
        " ___________ ",
        "/           \\",
        "| ///////// |",
        "| ///////// |",
        "| ///////// |",
        "| ///////// |",
        "| ///////// |",
        "| ///////// |",
        "| ///////// |",
        "| ///////// |",
        "| ///////// |",
        "\\___________/"
    },{
        " ___________ ",
        "/           \\",
        "| ######### |",
        "| ######### |",
        "| ######### |",
        "| ######### |",
        "| ######### |",
        "| ######### |",
        "| ######### |",
        "| ######### |",
        "| ######### |",
        "\\___________/"
    },{
        " ___________ ",
        "/           \\",
        "| +++++++++ |",
        "| +++++++++ |",
        "| +++++++++ |",
        "| +++++++++ |",
        "| +++++++++ |",
        "| +++++++++ |",
        "| +++++++++ |",
        "| +++++++++ |",
        "| +++++++++ |",
        "\\___________/"
    },{
        " ___________ ",
        "/A          \\",
        "|C          |",
        "|    ___    |",
        "|   /   \\   |",
        "|  _\\   /_  |",
        "| /       \\ |",
        "| \\__/ \\__/ |",
        "|    |_|    |",
        "|           |",
        "|          C|",
        "\\__________A/"
    },{
        " ___________ ",
        "/A          \\",
        "|D          |",
        "|     ^     |",
        "|    / \\    |",
        "|   /   \\   |",
        "|  (     )  |",
        "|   \\   /   |",
        "|    \\ /    |",
        "|     v     |",
        "|          D|",
        "\\__________A/"
    },{
        " ___________ ",
        "/A          \\",
        "|H          |",
        "|   __ __   |",
        "|  /  V  \\  |",
        "|  \\     /  |",
        "|   \\   /   |",
        "|    \\ /    |",
        "|     v     |",
        "|           |",
        "|          H|",
        "\\__________A/"
    },{
        " ___________ ",
        "/A          \\",
        "|S          |",
        "|           |",
        "|     ^     |",
        "|   /   \\   |",
        "|  /     \\  |",
        "|  \\_   _/  |",
        "|    |_|    |",
        "|           |",
        "|          S|",
        "\\__________A/"
    },{
        " ___________ ",
        "/2          \\",
        "|C          |",
        "|           |",
        "|     %     |",
        "|           |",
        "|           |",
        "|           |",
        "|     %     |",
        "|           |",
        "|          C|",
        "\\__________2/"
    },{
        " ___________ ",
        "/2          \\",
        "|D          |",
        "|           |",
        "|     +     |",
        "|           |",
        "|           |",
        "|           |",
        "|     +     |",
        "|           |",
        "|          D|",
        "\\__________2/"
    },{
        " ___________ ",
        "/2          \\",
        "|H          |",
        "|           |",
        "|     v     |",
        "|           |",
        "|           |",
        "|           |",
        "|     v     |",
        "|           |",
        "|          H|",
        "\\__________2/"
    },{
        " ___________ ",
        "/2          \\",
        "|S          |",
        "|           |",
        "|     ^     |",
        "|           |",
        "|           |",
        "|           |",
        "|     ^     |",
        "|           |",
        "|          S|",
        "\\__________2/"
    },{
        " ___________ ",
        "/3          \\",
        "|C          |",
        "|        %  |",
        "|           |",
        "|           |",
        "|     %     |",
        "|           |",
        "|           |",
        "|  %        |",
        "|          C|",
        "\\__________3/"
    },{
        " ___________ ",
        "/3          \\",
        "|D          |",
        "|        +  |",
        "|           |",
        "|           |",
        "|     +     |",
        "|           |",
        "|           |",
        "|  +        |",
        "|          D|",
        "\\__________3/"
    },{
        " ___________ ",
        "/3          \\",
        "|H          |",
        "|        v  |",
        "|           |",
        "|           |",
        "|     v     |",
        "|           |",
        "|           |",
        "|  v        |",
        "|          H|",
        "\\__________3/"
    },{
        " ___________ ",
        "/3          \\",
        "|S          |",
        "|        ^  |",
        "|           |",
        "|           |",
        "|     ^     |",
        "|           |",
        "|           |",
        "|  ^        |",
        "|          S|",
        "\\__________3/"
    },{
        " ___________ ",
        "/4          \\",
        "|C          |",
        "|           |",
        "|  %     %  |",
        "|           |",
        "|           |",
        "|           |",
        "|  %     %  |",
        "|           |",
        "|          C|",
        "\\__________4/"
    },{
        " ___________ ",
        "/4          \\",
        "|D          |",
        "|           |",
        "|  +     +  |",
        "|           |",
        "|           |",
        "|           |",
        "|  +     +  |",
        "|           |",
        "|          D|",
        "\\__________4/"
    },{
        " ___________ ",
        "/4          \\",
        "|H          |",
        "|           |",
        "|  v     v  |",
        "|           |",
        "|           |",
        "|           |",
        "|  v     v  |",
        "|           |",
        "|          H|",
        "\\__________4/"
    },{
        " ___________ ",
        "/4          \\",
        "|S          |",
        "|           |",
        "|  ^     ^  |",
        "|           |",
        "|           |",
        "|           |",
        "|  ^     ^  |",
        "|           |",
        "|          S|",
        "\\__________4/"
    },{
        " ___________ ",
        "/5          \\",
        "|C          |",
        "|  %     %  |",
        "|           |",
        "|           |",
        "|     %     |",
        "|           |",
        "|           |",
        "|  %     %  |",
        "|          C|",
        "\\__________5/"
    },{
        " ___________ ",
        "/5          \\",
        "|D          |",
        "|  +     +  |",
        "|           |",
        "|           |",
        "|     +     |",
        "|           |",
        "|           |",
        "|  +     +  |",
        "|          D|",
        "\\__________5/"
    },{
        " ___________ ",
        "/5          \\",
        "|H          |",
        "|  v     v  |",
        "|           |",
        "|           |",
        "|     v     |",
        "|           |",
        "|           |",
        "|  v     v  |",
        "|          H|",
        "\\__________5/"
    },{
        " ___________ ",
        "/5          \\",
        "|S          |",
        "|  ^     ^  |",
        "|           |",
        "|           |",
        "|     ^     |",
        "|           |",
        "|           |",
        "|  ^     ^  |",
        "|          S|",
        "\\__________5/"
    },{
        " ___________ ",
        "/6          \\",
        "|C          |",
        "|  %     %  |",
        "|           |",
        "|           |",
        "|  %     %  |",
        "|           |",
        "|           |",
        "|  %     %  |",
        "|          C|",
        "\\__________6/"
    },{
        " ___________ ",
        "/6          \\",
        "|D          |",
        "|  +     +  |",
        "|           |",
        "|           |",
        "|  +     +  |",
        "|           |",
        "|           |",
        "|  +     +  |",
        "|          D|",
        "\\__________6/"
    },{
        " ___________ ",
        "/6          \\",
        "|H          |",
        "|  v     v  |",
        "|           |",
        "|           |",
        "|  v     v  |",
        "|           |",
        "|           |",
        "|  v     v  |",
        "|          H|",
        "\\__________6/"
    },{
        " ___________ ",
        "/6          \\",
        "|S          |",
        "|  ^     ^  |",
        "|           |",
        "|           |",
        "|  ^     ^  |",
        "|           |",
        "|           |",
        "|  ^     ^  |",
        "|          S|",
        "\\__________6/"
    },{
        " ___________ ",
        "/7          \\",
        "|C          |",
        "|  %     %  |",
        "|           |",
        "|     %     |",
        "|           |",
        "|  %     %  |",
        "|           |",
        "|  %     %  |",
        "|          C|",
        "\\__________7/"
    },{
        " ___________ ",
        "/7          \\",
        "|D          |",
        "|  +     +  |",
        "|           |",
        "|     +     |",
        "|           |",
        "|  +     +  |",
        "|           |",
        "|  +     +  |",
        "|          D|",
        "\\__________7/"
    },{
        " ___________ ",
        "/7          \\",
        "|H          |",
        "|  v     v  |",
        "|           |",
        "|     v     |",
        "|           |",
        "|  v     v  |",
        "|           |",
        "|  v     v  |",
        "|          H|",
        "\\__________7/"
    },{
        " ___________ ",
        "/7          \\",
        "|S          |",
        "|  ^     ^  |",
        "|           |",
        "|     ^     |",
        "|           |",
        "|  ^     ^  |",
        "|           |",
        "|  ^     ^  |",
        "|          S|",
        "\\__________7/"
    },{
        " ___________ ",
        "/8          \\",
        "|C          |",
        "|  %     %  |",
        "|           |",
        "|  %     %  |",
        "|           |",
        "|  %     %  |",
        "|           |",
        "|  %     %  |",
        "|          C|",
        "\\__________8/"
    },{
        " ___________ ",
        "/8          \\",
        "|D          |",
        "|  +     +  |",
        "|           |",
        "|  +     +  |",
        "|           |",
        "|  +     +  |",
        "|           |",
        "|  +     +  |",
        "|          D|",
        "\\__________8/"
    },{
        " ___________ ",
        "/8          \\",
        "|H          |",
        "|  v     v  |",
        "|           |",
        "|  v     v  |",
        "|           |",
        "|  v     v  |",
        "|           |",
        "|  v     v  |",
        "|          H|",
        "\\__________8/"
    },{
        " ___________ ",
        "/8          \\",
        "|S          |",
        "|  ^     ^  |",
        "|           |",
        "|  ^     ^  |",
        "|           |",
        "|  ^     ^  |",
        "|           |",
        "|  ^     ^  |",
        "|          S|",
        "\\__________8/"
    },{
        " ___________ ",
        "/9          \\",
        "|C          |",
        "|  %     %  |",
        "|     %     |",
        "|  %     %  |",
        "|           |",
        "|  %     %  |",
        "|           |",
        "|  %     %  |",
        "|          C|",
        "\\__________9/"
    },{
        " ___________ ",
        "/9          \\",
        "|D          |",
        "|  +     +  |",
        "|     +     |",
        "|  +     +  |",
        "|           |",
        "|  +     +  |",
        "|           |",
        "|  +     +  |",
        "|          D|",
        "\\__________9/"
    },{
        " ___________ ",
        "/9          \\",
        "|H          |",
        "|  v     v  |",
        "|     v     |",
        "|  v     v  |",
        "|           |",
        "|  v     v  |",
        "|           |",
        "|  v     v  |",
        "|          H|",
        "\\__________9/"
    },{
        " ___________ ",
        "/9          \\",
        "|S          |",
        "|  ^     ^  |",
        "|     ^     |",
        "|  ^     ^  |",
        "|           |",
        "|  ^     ^  |",
        "|           |",
        "|  ^     ^  |",
        "|          S|",
        "\\__________9/"
    },{
        " ___________ ",
        "/10         \\",
        "|C          |",
        "|  %     %  |",
        "|     %     |",
        "|  %     %  |",
        "|           |",
        "|  %     %  |",
        "|     %     |",
        "|  %     %  |",
        "|          C|",
        "\\_________10/"
    },{
        " ___________ ",
        "/10         \\",
        "|D          |",
        "|  +     +  |",
        "|     +     |",
        "|  +     +  |",
        "|           |",
        "|  +     +  |",
        "|     +     |",
        "|  +     +  |",
        "|          D|",
        "\\_________10/"
    },{
        " ___________ ",
        "/10         \\",
        "|H          |",
        "|  v     v  |",
        "|     v     |",
        "|  v     v  |",
        "|           |",
        "|  v     v  |",
        "|     v     |",
        "|  v     v  |",
        "|          H|",
        "\\_________10/"
    },{
        " ___________ ",
        "/10         \\",
        "|S          |",
        "|  ^     ^  |",
        "|     ^     |",
        "|  ^     ^  |",
        "|           |",
        "|  ^     ^  |",
        "|     ^     |",
        "|  ^     ^  |",
        "|          S|",
        "\\_________10/"
    },{
        " ___________ ",
        "/J          \\",
        "|C _______  |",
        "| |__   __| |",
        "|  _ |_|    |",
        "| | /   \\   |",
        "| \\_\\   /_  |",
        "| /       \\ |",
        "| \\__/ \\__/ |",
        "|    |_|    |",
        "|          C|",
        "\\__________J/"
    },{
        " ___________ ",
        "/J          \\",
        "|D _______  |",
        "| |__   __| |",
        "|  _ | ^    |",
        "| | ||/ \\   |",
        "| \\__/   \\  |",
        "|   (     ) |",
        "|    \\   /  |",
        "|     \\ /   |",
        "|      v   D|",
        "\\__________J/"
    },{
        " ___________ ",
        "/J          \\",
        "|H _______  |",
        "| |__   __| |",
        "|  _ |_| __ |",
        "| | |/  V  \\|",
        "| \\__\\     /|",
        "|     \\   / |",
        "|      \\ /  |",
        "|       v   |",
        "|          H|",
        "\\__________J/"
    },{
        " ___________ ",
        "/J          \\",
        "|S _______  |",
        "| |__   __| |",
        "|  _ | |    |",
        "| | || ^    |",
        "| \\__/   \\  |",
        "|   /     \\ |",
        "|   \\_   _/ |",
        "|     |_|   |",
        "|          S|",
        "\\__________J/"
    },{
        " ___________ ",
        "/Q          \\",
        "|C __ ^ __  |",
        "| / /| |\\ \\ |",
        "|(o( |O| )o)|",
        "| \\ /   \\ / |",
        "| |_\\   /_| |",
        "| /       \\ |",
        "| \\__/ \\__/ |",
        "|    |_|    |",
        "|          C|",
        "\\__________Q/"
    },{
        " ___________ ",
        "/Q          \\",
        "|D __ ^ __  |",
        "| / /| |\\ \\ |",
        "|(o( |O|^)o)|",
        "| \\_\\| / \\/ |",
        "| |___/   \\ |",
        "|    (     )|",
        "|     \\   / |",
        "|      \\ /  |",
        "|       v  D|",
        "\\__________Q/"
    },{
        " ___________ ",
        "/Q          \\",
        "|H __ ^ __  |",
        "| / /| |\\ \\ |",
        "|(o( |O|_)o)|",
        "| \\ /  V  \\ |",
        "| |_\\     / |",
        "|    \\   /  |",
        "|     \\ /   |",
        "|      v    |",
        "|          H|",
        "\\__________Q/"
    },{
        " ___________ ",
        "/Q          \\",
        "|S __ ^ __  |",
        "| / /| |\\ \\ |",
        "|(o( |O| )o)|",
        "| \\_\\ ^ /_/ |",
        "| |_/   \\_| |",
        "|  /     \\  |",
        "|  \\_   _/  |",
        "|    |_|    |",
        "|          S|",
        "\\__________Q/"
    },{
        " ___________ ",
        "/K          \\",
        "|C          |",
        "| o O 0 O o |",
        "| |V V_V V| |",
        "| |_/   \\_| |",
        "|  _\\   /_  |",
        "| /       \\ |",
        "| \\__/ \\__/ |",
        "|    |_|    |",
        "|          C|",
        "\\__________K/"
    },{
        " ___________ ",
        "/K          \\",
        "|D          |",
        "| o O 0 O o |",
        "| |V V V^V| |",
        "| |____/ \\| |",
        "|     /   \\ |",
        "|    (     )|",
        "|     \\   / |",
        "|      \\ /  |",
        "|       v  D|",
        "\\__________K/"
    },{
        " ___________ ",
        "/K          \\",
        "|H          |",
        "| o O 0 O o |",
        "| |V V_V_V| |",
        "| |_/  V  \\ |",
        "|   \\     / |",
        "|    \\   /  |",
        "|     \\ /   |",
        "|      v    |",
        "|          H|",
        "\\__________K/"
    },{
        " ___________ ",
        "/K          \\",
        "|S          |",
        "| o O 0 O o |",
        "| |V V V V| |",
        "| |__ ^ __| |",
        "|   /   \\   |",
        "|  /     \\  |",
        "|  \\_   _/  |",
        "|    |_|    |",
        "|          S|",
        "\\__________K/"
    }
};

void drawCard(int number, int suit, int widthStart, int widthStop, int heightStart, int heightStop) {

    int x,y;

    for (y=heightStart; y<=heightStop; y++) {
        for (x=widthStart; x<=widthStop; x++) {
            printf("%c",deck[(number*4)+suit][y][x]);
        }
        if (heightStop>y) printf("\n");
    }

}

void drawHandFaceUp(int hand[13], int cardsLeft, int heightStart, int heightStop, int width) {

    int x,y,spaceLeft,spaceRight,cardWidth,extraSpace;

    cardWidth = (width - 13) / (cardsLeft - 1);
    if (cardWidth > 13) cardWidth = 13;
    extraSpace = (width - (13 + (cardWidth * cardsLeft)));
    spaceLeft = extraSpace / 2;
    spaceRight = (extraSpace / 2) + (extraSpace % 2);

    for (y=heightStart;y<=heightStop;y++) {
        
        for (x=0;x<spaceLeft;x++) printf(" ");
        
        for (x=0;x<cardsLeft-1;x++) {
            drawCard(hand[x]/4, hand[x]%4, 0, cardWidth - 1, y, y);
        }
        
        drawCard(hand[cardsLeft-1]/4, hand[cardsLeft-1]%4, 0, 12, y, y);
        
        for (x=0;x<spaceRight;x++) printf(" ");
        printf("\n");
    }

}

void drawHandFaceDown(int design, int cardsLeft, int heightStart, int heightStop, int width) {

    int x,y,spaceLeft,spaceRight,cardWidth,extraSpace;

    cardWidth = (width - 13) / (cardsLeft - 1);
    if (cardWidth > 13) cardWidth = 13;
    extraSpace = (width - (13 + (cardWidth * cardsLeft)));
    spaceLeft = extraSpace / 2;
    spaceRight = (extraSpace / 2) + (extraSpace % 2);

    for (y=heightStart;y<=heightStop;y++) {
        
        for (x=0;x<spaceLeft;x++) printf(" ");
        
        for (x=0;x<cardsLeft-1;x++) {
            drawCard(0, design, 0, cardWidth - 1, y, y);
        }
        
        drawCard(0, design, 0, 12, y, y);
        
        for (x=0;x<spaceRight;x++) printf(" ");
        printf("\n");
    }

}

