
/* Header file for lpr protocol and cli structures */
/* needs a job number field */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* A structure representation of input to lpr */
struct lpr_flags {
  size_t copies;  /* How many copies to print. */
  char *Jflag;    /* Job name to print on the bursot page. Normally the file's name is used. */
  char *Tflag;    /* Title name for pr(1), instead of file name. */
  char *Uflag;    /* user name to print on the burst page, also for accounting purposes. */
  char *username; /* username of user requesting printing */
  char *hostname; /* Hostname of the request's origin */
  char **file_names; /* all file names to be printed */
  char **mime_types; /* mime types that correspond to file_names char** */
  char *font;     /* Specifies a font to be mounted on font position i. */
  char *Cflag;    /* A c string: Job classification to use on the burst page. */
  char *Mflag;    /* Override libmagic mime type detection. */
  char *Pflag;    /* Force output to a specific printer. Normally, the default printer is used or the value of the environment variable PRINTER. */
  int iflag;      /* the output is indented by numcols. */
  int fontnum;    /* Number of font, I don't really understand this */
  int wflag;      /* page width for pr(1) */
  bool cflag;     /* The files are assumed to contain data produced by cifplot */
  bool dflag;     /* The files are assumed to contain data from tex (DVI) */
  bool fflag;     /* Use a filter which interprets the first character of each line as a standard FORTRAN carriages control character. */
  bool gflag;     /* The files are assumed to containt standard plot data as produced by the plot routines. */
  bool hflag;     /* Suppress the printing of the burst page. */
  bool lflag;     /* Use a filter which allows control characters to be printed and suppress page breaks. */
  bool mflag;     /* Send mail upon complettion. */
  bool nflag;     /* The file are assumed to contain data from ditroff (device independent troff). */
  bool oflag;     /* The files are assumed to be in postscript format. */
  bool pflag;     /* Use pr(1) to fornat the files (equivalent to print). */
  bool qflag;     /* Queue the print job but do not start the spooling daemom. */
  bool rflag;     /* Remove the file ipon completion of spooling or upon completion of printing (with -s option). */
  bool Rflag;     /* Writes a message to stdout containing the unique number which is used to identify this job. */
  bool sflag;     /* Use symlinks. Usually files are copied to the spool directory. */
  bool tflag;     /* The files are assumed to contain data from troff(1) (cat phototypesetter commands). */
  char pad[5];
};

/* lpr_flags protos */
struct lpr_flags * new_lpr_flags(void);
void free_lpr_flags(struct lpr_flags *j);
