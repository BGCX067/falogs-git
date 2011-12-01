//
//  Macro.h
//  fitPhoto
//
//  Created by JerryChan on 11-6-5.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//


#ifdef DEBUG
#else
#define NSLog(format, ...)
#endif

#define isExportLog                                                         1


CG_INLINE void writeLog(NSString *str, NSString *imgURL) {
    
#ifdef isExportLog
    
    NSString *dicpath = [NSString stringWithFormat:@"%@/Documents/logs",NSHomeDirectory()];
    NSString *path = [NSString stringWithFormat:@"%@/debug.html",dicpath];
    NSFileManager *manager = [NSFileManager defaultManager];
    if ([manager fileExistsAtPath:path] == NO) {
        [manager createDirectoryAtPath:dicpath withIntermediateDirectories:YES attributes:nil error:nil];
        [manager createFileAtPath:path contents:nil attributes:nil];
        
        NSString *stylePath = [NSString stringWithFormat:@"%@/FALog.style",[[NSBundle mainBundle] resourcePath]];
        NSString *styleStr = [NSString stringWithContentsOfFile:stylePath encoding:NSUTF8StringEncoding error:nil];
        NSLog(@"styleStr:%@",styleStr);
        str = [NSString stringWithFormat:@"%@ \n%@",styleStr,str];
    }
    
    if (imgURL != nil) {
        
    }
    
    NSDictionary * attributes = [manager attributesOfItemAtPath:path error:nil];
    long long fileSize = [[attributes objectForKey:NSFileSize] longLongValue];
    NSFileHandle *uFile = [NSFileHandle fileHandleForWritingAtPath:path];
    [uFile seekToFileOffset:fileSize];
    
    [uFile writeData:[str dataUsingEncoding:NSUTF8StringEncoding]];
    
#endif
    
}

///info
CG_INLINE void log4info(NSString *format,...) {
    
    va_list ap;
    va_start (ap, format);
    if (![format hasSuffix: @"\n"]) {
        format = [format stringByAppendingString: @"\n"];
    }
    
    NSString *body =  [[NSString alloc] initWithFormat:format arguments:ap];
    va_end(ap);
    
    NSString *logStr = [NSString stringWithFormat:@"[info]      >>>>>> %@",body];
    NSLog(@"%@",logStr);
    
    NSString *htmlOutput = [NSString stringWithFormat:@"<div class=\"info\"><b>%s %s</b><br/>%@</div>",__DATE__,__TIME__,body];
    writeLog(htmlOutput,nil);
    
    [body release];
    
}

///debug
CG_INLINE void log4debug(NSString *format,...) {
    
    va_list ap;
    va_start (ap, format);
    if (![format hasSuffix: @"\n"]) {
        format = [format stringByAppendingString: @"\n"];
    }
    
    NSString *body =  [[NSString alloc] initWithFormat:format arguments:ap];
    va_end(ap);
    
    NSString *logStr = [NSString stringWithFormat:@"[debug]     >>>>>> %@",body];
    NSLog(@"%@",logStr);
    
    NSString *htmlOutput = [NSString stringWithFormat:@"<div class=\"debug\"><b>%s %s</b><br/>%@</div>",__DATE__,__TIME__,body];
    writeLog(htmlOutput,nil);
    
    [body release];
    
}

///warning
CG_INLINE void log4warning(NSString *format,...) {
    
    va_list ap;
    va_start (ap, format);
    if (![format hasSuffix: @"\n"]) {
        format = [format stringByAppendingString: @"\n"];
    }
    
    NSString *body =  [[NSString alloc] initWithFormat:format arguments:ap];
    va_end(ap);
    
    NSString *logStr = [NSString stringWithFormat:@"[warning]   >>>>>> %@",body];
    NSLog(@"%@",logStr);
    
    NSString *htmlOutput = [NSString stringWithFormat:@"<div class=\"warning\"><b>%s %s</b><br/>%@</div>",__DATE__,__TIME__,body];
    writeLog(htmlOutput,nil);
    
    [body release];
    
}

///error
CG_INLINE void log4error(NSString *format,...) {
    
    va_list ap;
    va_start (ap, format);
    if (![format hasSuffix: @"\n"]) {
        format = [format stringByAppendingString: @"\n"];
    }
    
    NSString *body =  [[NSString alloc] initWithFormat:format arguments:ap];
    va_end(ap);
    
    NSString *logStr = [NSString stringWithFormat:@"[error]     >>>>>> %@",body];
    NSLog(@"%@",logStr);
    
    NSString *htmlOutput = [NSString stringWithFormat:@"<div class=\"error\"><b>%s %s</b><br/>%@</div>",__DATE__,__TIME__,body];
    writeLog(htmlOutput,nil);
    
    [body release];
    
}

CG_INLINE void log4section(){
    NSString *logStr = [NSString stringWithFormat:@"################################################"];
    NSLog(@"%@",logStr);
    
    NSString *htmlOutput = [NSString stringWithFormat:@"<h2>%s [%s]</h2><div>------------------------------------------------------</div>",__DATE__,__TIME__];
    writeLog(htmlOutput,nil);
}

///clear
CG_INLINE void log4clear(){
    NSString *path = [NSString stringWithFormat:@"%@/Documents/logs",NSHomeDirectory()];
    NSFileManager *manager = [NSFileManager defaultManager];
    [manager removeItemAtPath:path error:nil];
}



