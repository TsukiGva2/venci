#define CTRL_KEY(k) ((k) & 0x1f) // 0x1f aka 0001111

#define HI_NUM (1<<0)
#define HI_STRING (1<<1)

void disableRawMode();

enum ehi {
  HL_NORMAL = 0,
  HL_STRING,
  HL_KEYWORD,
  HL_TYPE,
  HL_COMMENT,
  HL_MCOMMENT,
  HL_NUMBER,
  HL_MATCH
};

enum ekey {
  BACKSPACE = 127,
  LEFT = 1000,
  RIGHT,
  UP,
  DOWN,
  PAGE_UP,
  PAGE_DOWN,
  HOME,
  END,
  DEL
};
