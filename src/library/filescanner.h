
#ifndef __FILESCANNER_H__
#define __FILESCANNER_H__

#include "db.h"


/* Actual scanners */
int
scan_metadata_ffmpeg(const char *file, struct media_file_info *mfi);

void
scan_playlist(const char *file, time_t mtime, int dir_id);

void
scan_smartpl(const char *file, time_t mtime, int dir_id);

#ifdef ITUNES
void
scan_itunes_itml(const char *file);
#endif

const char *
filename_from_path(const char *path);

char *
strip_extension(const char *path);

#endif /* !__FILESCANNER_H__ */
