struct song parseSong(char *songPath){
    struct song parsing;
    strcpy(parsing.path,songPath);
    char mode[30];
    FILE *file = fopen(songPath, "r");
    char line[128];
    while (fgets(line, sizeof(line), file) != NULL) {
        // printf("File content: %s\n", line);
        if(line[0]=='['){
            // index++;
            // indexs=line[0];
            if(line[1] == 'M'){
                strcpy(mode,"Meta");
            }else if(line[1] == 'G'){
                strcpy(mode,"Gen");
            }else{
                strcpy(mode,"UNDEFINED!!!");
            }
        }else{
            if (strcmp(mode,"Gen")==0){
                char* split=strtok(line,":");
                char statew[20];
                strcpy(statew,"null");
                while(split != NULL)
                {
                    char* word=split;
                    if(strcmp(statew,"null")==0){
                        split=strtok(NULL,"\r\n");
                        if(strcmp(word,"AudioFilename")==0){
                            strcpy(parsing.audio,split);
                            // printf(word);
                        }
                    }
                    split=strtok(NULL,"\r\n");
                    
                    // printf(word);
                }
             
            }
            if (strcmp(mode,"Meta")==0){
                // index++;
                char* split=strtok(line,":");
                char statew[20];
                strcpy(statew,"null");
                while(split != NULL)
                {
                    char* word=split;
                    if(strcmp(statew,"null")==0){
                            split=strtok(NULL,"\r\n");
                        if(strcmp(word,"Title")==0){
                            strcpy(parsing.title,split);
                        }
                        if(strcmp(word,"Artist")==0){
                            strcpy(parsing.artist,split);
                        }
                        if(strcmp(word,"Creator")==0){
                            strcpy(parsing.author,split);
                        }
                        if(strcmp(word,"Version")==0){
                            strcpy(parsing.difficulty,split);
                        }
                        if(strcmp(word,"Tags")==0){
                            char *tags;
                            char *heads;
                            char *tag=strtok_r(split, ",",&tags);
                            while(tag != NULL){
                                char *head=strtok_r(tag,":",&heads);

                                if(strcmp(head, "{\"Level\"")==0){
                                    tag=strtok_r(NULL,"\r\n",&heads);

                                    strcpy(parsing.level,tag);
                                }
                                if(strcmp(head, " \"FlavorText\"")==0||strcmp(head, "\"FlavorText\"")==0){
                                    tag=strtok_r(NULL,"\r\n",&heads);

                                    // strcpy(parsing.level,tag);
                                    strcpy(parsing.flavor,tag);
                                }
                                tag=strtok_r(NULL,",",&tags);
                            
                            }    
                        }
                    }
                            split=strtok(NULL,"\r\n");
                    // printf(word);
                }
            }
        }

    }
                            //printf(songs);
    sprintf(indexs, "%d", index);
    return (parsing);
}
struct beatmap parseBeats(char *songPath){
    struct beatmap parsing;
    FILE *file = fopen(songPath, "r");
    int buf_size = 0;
    int buf_used = 0;
    char line[128];
    char mode[18];
    // parsing.beats=NULL;

    int i = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        // printf("File content: %s\n", line);
        if(line[0]=='['){
            if(line[1]=='H'){
                strcpy(mode,"Hit");
            }
        }else if(strcmp(mode,"Hit")==0){
            struct beat *tmp;
            if (i == buf_size) {
                //need more space in the array

                buf_size += 20;
                tmp = realloc(parsing.beats, buf_size); // get a new larger array
                // if (!tmp) fatal_error();

                parsing.beats = tmp;
            }


            char* split=strtok(line,",");
            strtok(NULL,",");
            strtok(NULL,",");
            char* tmp2=split;
            int num1;
            sscanf(split, "%d", &num1);

            strtok(NULL,",");
            i=i+1;
        }
        
    }
    parsing.count=i;
    return parsing;
}


void printSong(struct song s){
    printf("\n --- \n\n");
    
    char temp[50];
    strcpy(temp, "Title : ");
    strcat(temp,s.title);
    printf(temp);

    strcpy(temp, "Artist : ");
    strcat(temp,s.artist);
    printf(temp);
    
    strcpy(temp, "Charted By : ");
    strcat(temp,s.author);
    printf(temp);
    printf("\n\n");

}