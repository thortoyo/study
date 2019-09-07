// 2�����x�N�g���\����
struct V {
  double x, y;
  V( double x=0, double y=0) : x(x), y(y) {}
  V& operator+=( const V& v) { x += v.x; y += v.y; return *this; }
  V operator+(const V& v) const {return V(*this) += v;}
  V& operator-=( const V& v) { x -= v.x; y -= v.y; return *this; }
  V operator-( const V& v) { return V(*this) -= v;}
  V& operator*=(double s) { x *= s; y *= s; return *this;}
  V operator*(double s) const { return V(*this) *= s;}
  V& operator/=(double s) { x /= s; y /= s; return *this;}
  V operator/(double s) const { return V(*this) /= s;}
  double dot(const V& v) const { return x*v.x + y*v.y; }	// ����
  double cross(const V& v) const { return x*v.y - y*v.x; }	// �O��
  double norm2() const { return x*x+y*y;}
  double norm() const { return sqrt(norm2());}
  int ort() const {  // orthant �ی�
    if (y>0 && x>0) return 1;
    else if (y>0 && x<=0) return 2;
    else if (y<=0 && x<=0) return 3;
    else return 4;
  }
  bool operator<(const V& v) const {
    int o = ort(), vo = v.ort();
    if (o != vo) return o < vo;
    return cross(v) > 0;
  }
};
istream& operator>>(istream& is, V& v) {
  is >> v.x >> v.y; return is;
}
ostream& operator<<(ostream& os, const V& v) {
  os << "(" << v.x << "," << v.y << ")"; return os;
}
