#ifndef __VORBIS_BRIDGE_H__
#define __VORBIS_BRIDGE_H__

#include <vorbis/vorbisfile.h>

#include "platform.h"

#define VORBIS_HOOKS \
	VORBIS_FWD   (oggpack_writecheck,          int,              (oggpack_buffer *b),                                                                                                           (b)) \
	VORBIS_FWD   (oggpack_look,                long,             (oggpack_buffer *b,int bits),                                                                                                  (b,bits)) \
	VORBIS_FWD   (oggpack_look1,               long,             (oggpack_buffer *b),                                                                                                           (b)) \
	VORBIS_FWD   (oggpack_read,                long,             (oggpack_buffer *b,int bits),                                                                                                  (b,bits)) \
	VORBIS_FWD   (oggpack_read1,               long,             (oggpack_buffer *b),                                                                                                           (b)) \
	VORBIS_FWD   (oggpack_bytes,               long,             (oggpack_buffer *b),                                                                                                           (b)) \
	VORBIS_FWD   (oggpack_bits,                long,             (oggpack_buffer *b),                                                                                                           (b)) \
	VORBIS_FWD   (oggpack_get_buffer,          unsigned char *,  (oggpack_buffer *b),                                                                                                           (b)) \
	VORBIS_FWD   (oggpackB_writecheck,         int,              (oggpack_buffer *b),                                                                                                           (b)) \
	VORBIS_FWD   (oggpackB_look,               long,             (oggpack_buffer *b,int bits),                                                                                                  (b,bits)) \
	VORBIS_FWD   (oggpackB_look1,              long,             (oggpack_buffer *b),                                                                                                           (b)) \
	VORBIS_FWD   (oggpackB_read,               long,             (oggpack_buffer *b,int bits),                                                                                                  (b,bits)) \
	VORBIS_FWD   (oggpackB_read1,              long,             (oggpack_buffer *b),                                                                                                           (b)) \
	VORBIS_FWD   (oggpackB_bytes,              long,             (oggpack_buffer *b),                                                                                                           (b)) \
	VORBIS_FWD   (oggpackB_bits,               long,             (oggpack_buffer *b),                                                                                                           (b)) \
	VORBIS_FWD   (oggpackB_get_buffer,         unsigned char *,  (oggpack_buffer *b),                                                                                                           (b)) \
	VORBIS_FWD   (ogg_stream_packetin,         int,              (ogg_stream_state *os, ogg_packet *op),                                                                                        (os, op)) \
	VORBIS_FWD   (ogg_stream_iovecin,          int,              (ogg_stream_state *os, ogg_iovec_t *iov,int count, long e_o_s, ogg_int64_t granulepos),                                        (os, iov,count, e_o_s, granulepos)) \
	VORBIS_FWD   (ogg_stream_pageout,          int,              (ogg_stream_state *os, ogg_page *og),                                                                                          (os, og)) \
	VORBIS_FWD   (ogg_stream_pageout_fill,     int,              (ogg_stream_state *os, ogg_page *og, int nfill),                                                                               (os, og, nfill)) \
	VORBIS_FWD   (ogg_stream_flush,            int,              (ogg_stream_state *os, ogg_page *og),                                                                                          (os, og)) \
	VORBIS_FWD   (ogg_stream_flush_fill,       int,              (ogg_stream_state *os, ogg_page *og, int nfill),                                                                               (os, og, nfill)) \
	VORBIS_FWD   (ogg_sync_init,               int,              (ogg_sync_state *oy),                                                                                                          (oy)) \
	VORBIS_FWD   (ogg_sync_clear,              int,              (ogg_sync_state *oy),                                                                                                          (oy)) \
	VORBIS_FWD   (ogg_sync_reset,              int,              (ogg_sync_state *oy),                                                                                                          (oy)) \
	VORBIS_FWD   (ogg_sync_destroy,            int,              (ogg_sync_state *oy),                                                                                                          (oy)) \
	VORBIS_FWD   (ogg_sync_check,              int,              (ogg_sync_state *oy),                                                                                                          (oy)) \
	VORBIS_FWD   (ogg_sync_buffer,             char *,           (ogg_sync_state *oy, long size),                                                                                               (oy, size)) \
	VORBIS_FWD   (ogg_sync_wrote,              int,              (ogg_sync_state *oy, long bytes),                                                                                              (oy, bytes)) \
	VORBIS_FWD   (ogg_sync_pageseek,           long,             (ogg_sync_state *oy,ogg_page *og),                                                                                             (oy,og)) \
	VORBIS_FWD   (ogg_sync_pageout,            int,              (ogg_sync_state *oy, ogg_page *og),                                                                                            (oy, og)) \
	VORBIS_FWD   (ogg_stream_pagein,           int,              (ogg_stream_state *os, ogg_page *og),                                                                                          (os, og)) \
	VORBIS_FWD   (ogg_stream_packetout,        int,              (ogg_stream_state *os,ogg_packet *op),                                                                                         (os,op)) \
	VORBIS_FWD   (ogg_stream_packetpeek,       int,              (ogg_stream_state *os,ogg_packet *op),                                                                                         (os,op)) \
	VORBIS_FWD   (ogg_stream_init,             int,              (ogg_stream_state *os,int serialno),                                                                                           (os,serialno)) \
	VORBIS_FWD   (ogg_stream_clear,            int,              (ogg_stream_state *os),                                                                                                        (os)) \
	VORBIS_FWD   (ogg_stream_reset,            int,              (ogg_stream_state *os),                                                                                                        (os)) \
	VORBIS_FWD   (ogg_stream_reset_serialno,   int,              (ogg_stream_state *os,int serialno),                                                                                           (os,serialno)) \
	VORBIS_FWD   (ogg_stream_destroy,          int,              (ogg_stream_state *os),                                                                                                        (os)) \
	VORBIS_FWD   (ogg_stream_check,            int,              (ogg_stream_state *os),                                                                                                        (os)) \
	VORBIS_FWD   (ogg_stream_eos,              int,              (ogg_stream_state *os),                                                                                                        (os)) \
	VORBIS_FWD   (ogg_page_version,            int,              (const ogg_page *og),                                                                                                          (og)) \
	VORBIS_FWD   (ogg_page_continued,          int,              (const ogg_page *og),                                                                                                          (og)) \
	VORBIS_FWD   (ogg_page_bos,                int,              (const ogg_page *og),                                                                                                          (og)) \
	VORBIS_FWD   (ogg_page_eos,                int,              (const ogg_page *og),                                                                                                          (og)) \
	VORBIS_FWD   (ogg_page_granulepos,         ogg_int64_t,      (const ogg_page *og),                                                                                                          (og)) \
	VORBIS_FWD   (ogg_page_serialno,           int,              (const ogg_page *og),                                                                                                          (og)) \
	VORBIS_FWD   (ogg_page_pageno,             long,             (const ogg_page *og),                                                                                                          (og)) \
	VORBIS_FWD   (ogg_page_packets,            int,              (const ogg_page *og),                                                                                                          (og)) \
	VORBIS_FWD   (vorbis_info_blocksize,       int,              (vorbis_info *vi,int zo),                                                                                                      (vi,zo)) \
	VORBIS_FWD   (vorbis_comment_query,        char *,           (vorbis_comment *vc, const char *tag, int count),                                                                              (vc, tag, count)) \
	VORBIS_FWD   (vorbis_comment_query_count,  int,              (vorbis_comment *vc, const char *tag),                                                                                         (vc, tag)) \
	VORBIS_FWD   (vorbis_block_init,           int,              (vorbis_dsp_state *v, vorbis_block *vb),                                                                                       (v, vb)) \
	VORBIS_FWD   (vorbis_block_clear,          int,              (vorbis_block *vb),                                                                                                            (vb)) \
	VORBIS_FWD   (vorbis_granule_time,         double,           (vorbis_dsp_state *v,ogg_int64_t granulepos),                                                                                  (v,granulepos)) \
	VORBIS_FWD   (vorbis_version_string,       const char *,     (void),                                                                                                                        ()) \
	VORBIS_FWD   (vorbis_analysis_init,        int,              (vorbis_dsp_state *v,vorbis_info *vi),                                                                                         (v,vi)) \
	VORBIS_FWD   (vorbis_commentheader_out,    int,              (vorbis_comment *vc, ogg_packet *op),                                                                                          (vc, op)) \
	VORBIS_FWD   (vorbis_analysis_headerout,   int,              (vorbis_dsp_state *v,vorbis_comment *vc,ogg_packet *op,ogg_packet *op_comm,ogg_packet *op_code),                               (v,vc,op,op_comm,op_code)) \
	VORBIS_FWD   (vorbis_analysis_buffer,      float **,         (vorbis_dsp_state *v,int vals),                                                                                                (v,vals)) \
	VORBIS_FWD   (vorbis_analysis_wrote,       int,              (vorbis_dsp_state *v,int vals),                                                                                                (v,vals)) \
	VORBIS_FWD   (vorbis_analysis_blockout,    int,              (vorbis_dsp_state *v,vorbis_block *vb),                                                                                        (v,vb)) \
	VORBIS_FWD   (vorbis_analysis,             int,              (vorbis_block *vb,ogg_packet *op),                                                                                             (vb,op)) \
	VORBIS_FWD   (vorbis_bitrate_addblock,     int,              (vorbis_block *vb),                                                                                                            (vb)) \
	VORBIS_FWD   (vorbis_bitrate_flushpacket,  int,              (vorbis_dsp_state *vd,ogg_packet *op),                                                                                         (vd,op)) \
	VORBIS_FWD   (vorbis_synthesis_idheader,   int,              (ogg_packet *op),                                                                                                              (op)) \
	VORBIS_FWD   (vorbis_synthesis_headerin,   int,              (vorbis_info *vi,vorbis_comment *vc,ogg_packet *op),                                                                           (vi,vc,op)) \
	VORBIS_FWD   (vorbis_synthesis_init,       int,              (vorbis_dsp_state *v,vorbis_info *vi),                                                                                         (v,vi)) \
	VORBIS_FWD   (vorbis_synthesis_restart,    int,              (vorbis_dsp_state *v),                                                                                                         (v)) \
	VORBIS_FWD   (vorbis_synthesis,            int,              (vorbis_block *vb,ogg_packet *op),                                                                                             (vb,op)) \
	VORBIS_FWD   (vorbis_synthesis_trackonly,  int,              (vorbis_block *vb,ogg_packet *op),                                                                                             (vb,op)) \
	VORBIS_FWD   (vorbis_synthesis_blockin,    int,              (vorbis_dsp_state *v,vorbis_block *vb),                                                                                        (v,vb)) \
	VORBIS_FWD   (vorbis_synthesis_pcmout,     int,              (vorbis_dsp_state *v,float ***pcm),                                                                                            (v,pcm)) \
	VORBIS_FWD   (vorbis_synthesis_lapout,     int,              (vorbis_dsp_state *v,float ***pcm),                                                                                            (v,pcm)) \
	VORBIS_FWD   (vorbis_synthesis_read,       int,              (vorbis_dsp_state *v,int samples),                                                                                             (v,samples)) \
	VORBIS_FWD   (vorbis_packet_blocksize,     long,             (vorbis_info *vi,ogg_packet *op),                                                                                              (vi,op)) \
	VORBIS_FWD   (vorbis_synthesis_halfrate,   int,              (vorbis_info *v,int flag),                                                                                                     (v,flag)) \
	VORBIS_FWD   (vorbis_synthesis_halfrate_p, int,              (vorbis_info *v),                                                                                                              (v)) \
	VORBIS_FWD   (ov_clear,                    int,              (OggVorbis_File *vf),                                                                                                          (vf)) \
	VORBIS_FWD   (ov_fopen,                    int,              (const char *path,OggVorbis_File *vf),                                                                                         (path,vf)) \
	VORBIS_FWD   (ov_open,                     int,              (FILE *f,OggVorbis_File *vf,const char *initial,long ibytes),                                                                  (f,vf,initial,ibytes)) \
	VORBIS_FWD   (ov_open_callbacks,           int,              (void *datasource, OggVorbis_File *vf,const char *initial, long ibytes, ov_callbacks callbacks),                               (datasource, vf,initial, ibytes, callbacks)) \
	VORBIS_FWD   (ov_test,                     int,              (FILE *f,OggVorbis_File *vf,const char *initial,long ibytes),                                                                  (f,vf,initial,ibytes)) \
	VORBIS_FWD   (ov_test_callbacks,           int,              (void *datasource, OggVorbis_File *vf,const char *initial, long ibytes, ov_callbacks callbacks),                               (datasource, vf,initial, ibytes, callbacks)) \
	VORBIS_FWD   (ov_test_open,                int,              (OggVorbis_File *vf),                                                                                                          (vf)) \
	VORBIS_FWD   (ov_bitrate,                  long,             (OggVorbis_File *vf,int i),                                                                                                    (vf,i)) \
	VORBIS_FWD   (ov_bitrate_instant,          long,             (OggVorbis_File *vf),                                                                                                          (vf)) \
	VORBIS_FWD   (ov_streams,                  long,             (OggVorbis_File *vf),                                                                                                          (vf)) \
	VORBIS_FWD   (ov_seekable,                 long,             (OggVorbis_File *vf),                                                                                                          (vf)) \
	VORBIS_FWD   (ov_serialnumber,             long,             (OggVorbis_File *vf,int i),                                                                                                    (vf,i)) \
	VORBIS_FWD   (ov_raw_total,                ogg_int64_t,      (OggVorbis_File *vf,int i),                                                                                                    (vf,i)) \
	VORBIS_FWD   (ov_pcm_total,                ogg_int64_t,      (OggVorbis_File *vf,int i),                                                                                                    (vf,i)) \
	VORBIS_FWD   (ov_time_total,               double,           (OggVorbis_File *vf,int i),                                                                                                    (vf,i)) \
	VORBIS_FWD   (ov_raw_seek,                 int,              (OggVorbis_File *vf,ogg_int64_t pos),                                                                                          (vf,pos)) \
	VORBIS_FWD   (ov_pcm_seek,                 int,              (OggVorbis_File *vf,ogg_int64_t pos),                                                                                          (vf,pos)) \
	VORBIS_FWD   (ov_pcm_seek_page,            int,              (OggVorbis_File *vf,ogg_int64_t pos),                                                                                          (vf,pos)) \
	VORBIS_FWD   (ov_time_seek,                int,              (OggVorbis_File *vf,double pos),                                                                                               (vf,pos)) \
	VORBIS_FWD   (ov_time_seek_page,           int,              (OggVorbis_File *vf,double pos),                                                                                               (vf,pos)) \
	VORBIS_FWD   (ov_raw_seek_lap,             int,              (OggVorbis_File *vf,ogg_int64_t pos),                                                                                          (vf,pos)) \
	VORBIS_FWD   (ov_pcm_seek_lap,             int,              (OggVorbis_File *vf,ogg_int64_t pos),                                                                                          (vf,pos)) \
	VORBIS_FWD   (ov_pcm_seek_page_lap,        int,              (OggVorbis_File *vf,ogg_int64_t pos),                                                                                          (vf,pos)) \
	VORBIS_FWD   (ov_time_seek_lap,            int,              (OggVorbis_File *vf,double pos),                                                                                               (vf,pos)) \
	VORBIS_FWD   (ov_time_seek_page_lap,       int,              (OggVorbis_File *vf,double pos),                                                                                               (vf,pos)) \
	VORBIS_FWD   (ov_raw_tell,                 ogg_int64_t,      (OggVorbis_File *vf),                                                                                                          (vf)) \
	VORBIS_FWD   (ov_pcm_tell,                 ogg_int64_t,      (OggVorbis_File *vf),                                                                                                          (vf)) \
	VORBIS_FWD   (ov_time_tell,                double,           (OggVorbis_File *vf),                                                                                                          (vf)) \
	VORBIS_FWD   (ov_info,                     vorbis_info *,    (OggVorbis_File *vf,int link),                                                                                                 (vf,link)) \
	VORBIS_FWD   (ov_comment,                  vorbis_comment *, (OggVorbis_File *vf,int link),                                                                                                 (vf,link)) \
	VORBIS_FWD   (ov_read_float,               long,             (OggVorbis_File *vf,float ***pcm_channels,int samples,int *bitstream),                                                         (vf,pcm_channels,samples,bitstream)) \
	VORBIS_FWD   (ov_read_filter,              long,             (OggVorbis_File *vf,char *buffer,int length,int bigendianp,int word,int sgned,int *bitstream,void *filter,void *filter_param), (vf,buffer,length,bigendianp,word,sgned,bitstream,filter,filter_param)) \
	VORBIS_FWD   (ov_read,                     long,             (OggVorbis_File *vf,char *buffer,int length,int bigendianp,int word,int sgned,int *bitstream),                                 (vf,buffer,length,bigendianp,word,sgned,bitstream)) \
	VORBIS_FWD   (ov_crosslap,                 int,              (OggVorbis_File *vf1,OggVorbis_File *vf2),                                                                                     (vf1,vf2)) \
	VORBIS_FWD   (ov_halfrate,                 int,              (OggVorbis_File *vf,int flag),                                                                                                 (vf,flag)) \
	VORBIS_FWD   (ov_halfrate_p,               int,              (OggVorbis_File *vf),                                                                                                          (vf)) \
	VORBIS_FWD_NR(oggpack_writeinit,           void,             (oggpack_buffer *b),                                                                                                           (b)) \
	VORBIS_FWD_NR(oggpack_writetrunc,          void,             (oggpack_buffer *b,long bits),                                                                                                 (b,bits)) \
	VORBIS_FWD_NR(oggpack_writealign,          void,             (oggpack_buffer *b),                                                                                                           (b)) \
	VORBIS_FWD_NR(oggpack_writecopy,           void,             (oggpack_buffer *b,void *source,long bits),                                                                                    (b,source,bits)) \
	VORBIS_FWD_NR(oggpack_reset,               void,             (oggpack_buffer *b),                                                                                                           (b)) \
	VORBIS_FWD_NR(oggpack_writeclear,          void,             (oggpack_buffer *b),                                                                                                           (b)) \
	VORBIS_FWD_NR(oggpack_readinit,            void,             (oggpack_buffer *b,unsigned char *buf,int bytes),                                                                              (b,buf,bytes)) \
	VORBIS_FWD_NR(oggpack_write,               void,             (oggpack_buffer *b,unsigned long value,int bits),                                                                              (b,value,bits)) \
	VORBIS_FWD_NR(oggpack_adv,                 void,             (oggpack_buffer *b,int bits),                                                                                                  (b,bits)) \
	VORBIS_FWD_NR(oggpack_adv1,                void,             (oggpack_buffer *b),                                                                                                           (b)) \
	VORBIS_FWD_NR(oggpackB_writeinit,          void,             (oggpack_buffer *b),                                                                                                           (b)) \
	VORBIS_FWD_NR(oggpackB_writetrunc,         void,             (oggpack_buffer *b,long bits),                                                                                                 (b,bits)) \
	VORBIS_FWD_NR(oggpackB_writealign,         void,             (oggpack_buffer *b),                                                                                                           (b)) \
	VORBIS_FWD_NR(oggpackB_writecopy,          void,             (oggpack_buffer *b,void *source,long bits),                                                                                    (b,source,bits)) \
	VORBIS_FWD_NR(oggpackB_reset,              void,             (oggpack_buffer *b),                                                                                                           (b)) \
	VORBIS_FWD_NR(oggpackB_writeclear,         void,             (oggpack_buffer *b),                                                                                                           (b)) \
	VORBIS_FWD_NR(oggpackB_readinit,           void,             (oggpack_buffer *b,unsigned char *buf,int bytes),                                                                              (b,buf,bytes)) \
	VORBIS_FWD_NR(oggpackB_write,              void,             (oggpack_buffer *b,unsigned long value,int bits),                                                                              (b,value,bits)) \
	VORBIS_FWD_NR(oggpackB_adv,                void,             (oggpack_buffer *b,int bits),                                                                                                  (b,bits)) \
	VORBIS_FWD_NR(oggpackB_adv1,               void,             (oggpack_buffer *b),                                                                                                           (b)) \
	VORBIS_FWD_NR(ogg_page_checksum_set,       void,             (ogg_page *og),                                                                                                                (og)) \
	VORBIS_FWD_NR(ogg_packet_clear,            void,             (ogg_packet *op),                                                                                                              (op)) \
	VORBIS_FWD_NR(vorbis_info_init,            void,             (vorbis_info *vi),                                                                                                             (vi)) \
	VORBIS_FWD_NR(vorbis_info_clear,           void,             (vorbis_info *vi),                                                                                                             (vi)) \
	VORBIS_FWD_NR(vorbis_comment_init,         void,             (vorbis_comment *vc),                                                                                                          (vc)) \
	VORBIS_FWD_NR(vorbis_comment_add,          void,             (vorbis_comment *vc, const char *comment),                                                                                     (vc, comment)) \
	VORBIS_FWD_NR(vorbis_comment_add_tag,      void,             (vorbis_comment *vc,const char *tag, const char *contents),                                                                    (vc,tag, contents)) \
	VORBIS_FWD_NR(vorbis_comment_clear,        void,             (vorbis_comment *vc),                                                                                                          (vc)) \
	VORBIS_FWD_NR(vorbis_dsp_clear,            void,             (vorbis_dsp_state *v),                                                                                                         (v))

#endif /* __VORBIS_BRIDGE_H__ */