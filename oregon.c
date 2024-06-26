#include <stdio.h>
#include <stdlib.h>
//TODO rename MainCharacter
typedef struct {
  char *wagonLeaderName;
  char *career;
  int wallet;
} wagon;

void set_wagonLeader(wagon *player , char *wagonLeader ){
  player->wagonLeaderName = wagonLeader;
}

void clear_input_buffer(void){
  int c;
  while((c =getchar()) != '\n' && c != EOF);
}

void chooseCharacter(void)
{
  char wagonLeader[10];
  char wagonMembers[4][10];

  int moveChar;

  printf("Many kinds of people made the trip to Oregon.\n You may:\n \t 1. Be a banker from Boston\n \t 2. Be a Carpenter from Ohio\n \t 3. Be a farmer from Illinois\n \t 4. Find out the differences between these choices\nWhat is your choice? ");
  scanf("%d",&moveChar); //scanf takes the format argument and a pointer of the variable and not the variable itself
  int c;
  while((c = getchar()) != '\n' && c != EOF);
  printf("%d\n",moveChar);

  if (moveChar == 1)
  {
    wagon player = {.career="banker", .wallet=1600};
    printf("You are a Banker \n  wallet=$ %d\n", player.wallet);
    printf("Enter the name of the wagon leader: \n");
    set_wagonLeader(&player, fgets(wagonLeader,10,stdin));
    printf("WagonLeader is - %s \n",player.wagonLeaderName);
  }
  else if (moveChar == 2)
  {
    wagon player = {.career="carpenter", .wallet=800};
    printf("You are a Carpenter \n wallet=$ %d\n",player.career, player.wallet);
  }
  else if(moveChar == 3)
  {
    wagon player = {.career="farmer", .wallet=400};
    printf("You are a Farmer \n  wallet=$ %d\n",player.career, player.wallet);
  }
  else if (moveChar == 4)
  {
    printf("Travelling to Oregon isn't easy!\nBut if you're a banker, you'll have more money for supplies and services than a farmer or a carpenter");
    printf("\n");
    printf("However, the harder you have to try, the more points you deserve!\n Therefore, the farmer earns the greatest number of points and the banker earns the least");
    chooseCharacter();
  } else{
    printf("Wrong input, try again");
    chooseCharacter();
  }
  printf("Enter the people who will accompany in this journey\n");
  for (int i =0; i < 4; i++){
    printf("%d  ",i+1);
    fgets(wagonMembers[i],10,stdin);
    clear_input_buffer();
  }
  printf("\n");
  //TODO fix first name of the wagonMembers
  printf("Here are the friends that will accompany you for the adventure:\n");
  for (int i = 0; i < 4; i++){
    printf(" %d: %s",i,wagonMembers[i]);

  }
}


void learnMore(void)
{
  printf("Try taking a journey by covered wagon across 2000 miles of plains, rivers, and mountains.\n");
  printf("Try!\n");
  printf("On the plains, will you slosh your oxen through mud and water-filled ruts or will you plod through dust six inches deep?\n");
  printf("How will you cross the rivers? If you have money, you might take a ferry (if there is a ferry).\n Or, you can ford the river and hope you and your wagon aren't swallowed alive!\n");
}

int main(void)
{
  char c;
  printf("Welcome to The Oregon Trail\n You may: (Enter Number)\n \t 1. Travel the trail \n \t 2. Learn about the trail \n \t 3. Quit\n");
  scanf("%c",&c);
  int move = c - '0';
  switch (move){
    case 1:
      chooseCharacter();
      break;
    case 2:
      learnMore();
      break;
    case 3:
      printf("Bye\n");
      break;
    default:
      printf("Try again input doesn't match the options\n");
  }
  return 0;
}
