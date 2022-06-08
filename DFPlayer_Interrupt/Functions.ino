
  
//   if(digitalRead(pb)==HIGH){
//    
//   }else{
//      mp3.play(6);
//   }


//     scrollText("Hello!   ");
//     delay(500);
//     spiral(35);
//     stripe(50);

//-----------------Scrolling Text----------------------//
void scrollText(const char *p){
  uint8_t charWidth;
  uint8_t cBuf[8]; 
  mx.clear();

  while (*p != '\0'){
    charWidth = mx.getChar(*p++, sizeof(cBuf) / sizeof(cBuf[0]), cBuf);
    for (uint8_t i=0; i<=charWidth; i++) {
      mx.transform(MD_MAX72XX::TSL);
      if (i < charWidth)
        mx.setColumn(0, cBuf[i]);
      delay(DELAYTIME);
    }
  }
}

//-------------------Spiral--------------------//
void spiral(int SpiralSpeed){
  int  rmin = 0, rmax = ROW_SIZE-1;
  int  cmin = 0, cmax = (COL_SIZE*MAX_DEVICES)-1;

  while ((rmax > rmin) && (cmax > cmin)){
    // do row
    for (int i=cmin; i<=cmax; i++){
      mx.setPoint(rmin, i, true);
      delay(SpiralSpeed/MAX_DEVICES);
    }
    rmin++;

    // do column
    for (uint8_t i=rmin; i<=rmax; i++){
      mx.setPoint(i, cmax, true);
      delay(SpiralSpeed/MAX_DEVICES);
    }
    cmax--;

    // do row
    for (int i=cmax; i>=cmin; i--){
      mx.setPoint(rmax, i, true);
      delay(SpiralSpeed/MAX_DEVICES);
    }
    rmax--;

    // do column
    for (uint8_t i=rmax; i>=rmin; i--){
      mx.setPoint(i, cmin, true);
      delay(SpiralSpeed/MAX_DEVICES);
    } 
    cmin++;
  }
}

//-------------------Stripe--------------------//
void stripe(int WipeSpeed){
  const uint16_t maxCol = MAX_DEVICES*ROW_SIZE;
  const uint8_t stripeWidth = 10;

  for (uint16_t col=0; col<maxCol + ROW_SIZE + stripeWidth; col++){
    for (uint8_t row=0; row < ROW_SIZE; row++){
      mx.setPoint(row, col-row, true);
      mx.setPoint(row, col-row - stripeWidth, false);
    }
    delay(WipeSpeed);
  }
}
