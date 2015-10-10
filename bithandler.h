/* 
 * File:   bithandler.h
 * Author: Miguel
 *
 * Created on 10 de Outubro de 2015, 2:56
 */

#ifndef BITHANDLER_H
#define	BITHANDLER_H

#ifdef	__cplusplus
extern "C" {
#endif

#define bit_set(p,m) ((p) |= (1<<m))
#define bit_clear(p,m) ((p) &= ~(1<<m))
#define bit_write(c,p,m) (c ? bit_set(p, m) : bit_clear(p,m))

#define LOW 0
#define HIGH 1

#ifdef	__cplusplus
}
#endif

#endif	/* BITHANDLER_H */

