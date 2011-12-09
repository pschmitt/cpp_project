/*
 *  doxygenoutput.h
 *
 *  Created by Siham El Hadri privat on 1/6/11.
 *  Copyright 2011 MPI-SWS. All rights reserved.
 *
 */

#include <time.h>
#include <string.h>

class DoxygenOutput {
public:
	const char *description;
	const char *name;
	const char *brief;

	DoxygenOutput() //Constructor 
	{ 
		description="";
		name="";
		brief="";
	};
	
	~DoxygenOutput() //Destructor
	{ }
	
	
	int generateComment (const char text[]){
		printf("/*! \n");
		printf("%s\n",text);
		printf("*/\n");
		return 0;
	}
};

class DoxygenOutputFunction : public DoxygenOutput{
public:
	const char * returnvalue;
	//hoechstens 10 params zulassen
	const char * params[10];
	
	DoxygenOutputFunction() //Constructor 
	{ 
		for(int i=0;i<10;i++){
			params[i]="";
		}
	};
	
	~DoxygenOutputFunction() //Destructor
	{ 
	} ;
	
	int generateCommentForFunction(DoxygenOutputFunction output) {

		char text[1000]="";
		strcat(text,"\t\\fn ");
		strcat(text,output.name);
		strcat(text,"\n\t\\brief ");
		strcat(text,output.brief);
		strcat(text,"\n\n\t");
		strcat(text,output.description);
		strcat(text,"\n");
		
		for(int i=0;i<10;i++){
			if (strlen(output.params[i])) {
			strcat(text,"\n\t\\param ");
			strcat(text,output.params[i]);
			}
		}
		
		strcat(text,"\n\t\\return ");
		strcat(text,output.returnvalue);
		
		generateComment(text);
		return 0;
	}
};

class DoxygenOutputFile : public DoxygenOutput{
public:
	const char * author;
	const char * date;
	const char * license;
	const char * build;
	
	DoxygenOutputFile() //Constructor 
	{ 
		time_t t;
		struct tm *ts;
		
		t = time(NULL);
		ts = localtime(&t);
		date=asctime(ts);
		
		author="";
		license="";
		build="";
	};
	
	~DoxygenOutputFile() //Destructor
	{ } ;
	
	int generateCommentForFile(DoxygenOutputFile output) {
		char text[1000]="";
		strcat(text,"\t\\file ");
		strcat(text,output.name);
		strcat(text,"\n\t\\author ");
		strcat(text,output.author);
		strcat(text,"\n\t\\date ");
		strcat(text,output.date);
		strcat(text,"\n\t\\brief ");
		strcat(text,output.brief);
		strcat(text,"\n\t\\section LICENSE ");
		strcat(text,output.license);
		strcat(text,"\n\t\\section BUILD ");
		strcat(text,output.build);
		strcat(text,"\n\t\\section DESCRIPTION ");
		strcat(text,output.description);
		generateComment(text);
		return 0;
	}
};

class DoxygenOutputEnumeration : public DoxygenOutput{
public:
	
	DoxygenOutputEnumeration() //Constructor 
	{ 
	};
	~DoxygenOutputEnumeration() //Destructor
	{ } ;
	
	int generateCommentForEnumeration(DoxygenOutputEnumeration output) {
		char text[1000]="";
		strcat(text,"\t\\enum");
		strcat(text,output.name);
		strcat(text,"\n\t\\brief");
		strcat(text,output.brief);
		strcat(text,"\n\n\t");
		strcat(text,output.description);
		generateComment(text);
		return 0;
	}
};

class DoxygenOutputVariable : public DoxygenOutput{
public:
	
	DoxygenOutputVariable() //Constructor 
	{ 
	};
	~DoxygenOutputVariable() //Destructor
	{ } ;
	
	int generateCommentForVariable(DoxygenOutputVariable output) {
		char text[1000]="";
		strcat(text,"\t\\var ");
		strcat(text,output.name);
		strcat(text,"\n\t\\brief ");
		strcat(text,output.brief);
		strcat(text,"\n\n\t");
		strcat(text,output.description);
		generateComment(text);
		return 0;
	}
};

class DoxygenOutputStruct : public DoxygenOutput{
public:
	
	DoxygenOutputStruct() //Constructor 
	{ 
	};
	~DoxygenOutputStruct() //Destructor
	{ } ;
	
	int generateCommentForStruct(DoxygenOutputStruct output) {
		char text[1000]="";
		strcat(text,"\t\\struct ");
		strcat(text,output.name);
		strcat(text,"\n\t\\brief ");
		strcat(text,output.brief);
		strcat(text,"\n\n\t");
		strcat(text,output.description);
		generateComment(text);
		return 0;
	}
};
