//index.js
//获取应用实例
const app = getApp()

Page({
  data: {
    word: '',
    wordInfo: '',
    phoSpell: '',
    condition:''
  },

  //绑定输入数据
  inputword: function (e) {
    this.setData({
      word: e.detail.value
    })
  },

  //调用API
  getwordinfo: function () {
    var that = this;
    var word = this.data.word;
    var option = "1"; //改变方法
    this.apiRequest(this.oxfordsj, this.callback, word, option);
  },

  //API请求
  apiRequest: function (oxfordsj, callback, word, op) {
    var word = word;
    var option = op;
    //判断方法

    if (option != 1) {
      wx.request({
        url: app.globalUrl.wbUrl + word + app.globalData.wbkey,
        header: {
          'Content-type': 'application/json',
          key: ''
        },
        success: function (res) {
          callback(res.data)
          console.log(res)
        }
      })
    } else {
      wx.request({
        url: app.globalUrl.oxfordUrl + word,
        method: 'GET',
        header: {
          'Content-type': 'application/json',
          app_id: '',
          app_key: ''
        },
        success: function (res) {
          oxfordsj(res.data.results, callback)
          //console.log(res)
        }
      })

    }
  },

  //修饰Oxford数据
  oxfordsj: function (res, callback) {
    var words = []
    var i;
    for (i = 0; i < res.length; i++) {
      var citiao = res[i].lexicalEntries;
      var temp = {
        entries: citiao
      }
      words.push(temp);
    }
    callback(...words)
  },
  //返回数据，并整理
  callback: function (res) {
    //push数据
     console.log(res)
    this.vioce(res.entries[0])
    this.setData({
      wordInfo: res
    })
    this.setData({
      condition: 1
    })
  },

  vioce: function (res) {
    //查询第一次播放
    var url = res.pronunciations[0].audioFile
    wx.playBackgroundAudio({
      dataUrl: url
    })
    var temp = res.pronunciations[0].phoneticSpelling
    this.setData({
      phoSpell: temp
    })
    //本地存储音频地址
    wx.setStorage({
      key: 'porUrl',
      data: url
    })
    //console.log(url)
  },

  pronunce: function (e) {
    wx.getStorage({
      key: 'porUrl',
      success: function (res) {
        var url = res.data
        wx.playBackgroundAudio({
          dataUrl: url,
        })
        // console.log(res)
      },
    })

  }

}) //Page结束
