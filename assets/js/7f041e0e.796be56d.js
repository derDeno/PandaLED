"use strict";(self.webpackChunkdocs=self.webpackChunkdocs||[]).push([[247],{5957:(e,n,t)=>{t.r(n),t.d(n,{assets:()=>c,contentTitle:()=>a,default:()=>h,frontMatter:()=>s,metadata:()=>i,toc:()=>d});const i=JSON.parse('{"id":"getting-started/what-can-i-connect","title":"What To Connect","description":"The PandaLED PCB offers two primary outputs, along with GPIO pins for added flexibility.","source":"@site/docs/getting-started/what-can-i-connect.md","sourceDirName":"getting-started","slug":"/getting-started/what-can-i-connect","permalink":"/PandaLED/getting-started/what-can-i-connect","draft":false,"unlisted":false,"tags":[],"version":"current","sidebarPosition":2,"frontMatter":{"title":"What To Connect","sidebar_position":2},"sidebar":"docsSidebar","previous":{"title":"Installation","permalink":"/PandaLED/getting-started/installation"},"next":{"title":"Sourcing Parts","permalink":"/PandaLED/getting-started/sourcing-parts"}}');var o=t(4848),r=t(8453);const s={title:"What To Connect",sidebar_position:2},a="What Can I Connect to the PandaLED",c={},d=[{value:"WLED",id:"wled",level:2},{value:"Generic / Analog",id:"generic--analog",level:2},{value:"GPIO",id:"gpio",level:2}];function l(e){const n={admonition:"admonition",h1:"h1",h2:"h2",header:"header",hr:"hr",img:"img",li:"li",p:"p",ul:"ul",...(0,r.R)(),...e.components};return(0,o.jsxs)(o.Fragment,{children:[(0,o.jsx)(n.header,{children:(0,o.jsx)(n.h1,{id:"what-can-i-connect-to-the-pandaled",children:"What Can I Connect to the PandaLED"})}),"\n",(0,o.jsx)(n.p,{children:"The PandaLED PCB offers two primary outputs, along with GPIO pins for added flexibility.\r\nBelow is an overview of the available connections and their specifications."}),"\n",(0,o.jsx)(n.hr,{}),"\n",(0,o.jsx)(n.h2,{id:"wled",children:"WLED"}),"\n",(0,o.jsx)(n.p,{children:"The WLED output port is a 3-pin connector designed exclusively for use with 5V LED strips, such as the WS2812b."}),"\n",(0,o.jsxs)(n.ul,{children:["\n",(0,o.jsx)(n.li,{children:"Port Type: 3-pin"}),"\n",(0,o.jsx)(n.li,{children:"Voltage: 5V using USB-C or using the DC connector with 12V or 24V."}),"\n",(0,o.jsx)(n.li,{children:"Supported LEDs: WS2812b (5V)"}),"\n",(0,o.jsx)(n.li,{children:"Pin Layout: Printed on the bottom side of the PCB"}),"\n"]}),"\n",(0,o.jsx)(n.hr,{}),"\n",(0,o.jsx)(n.h2,{id:"generic--analog",children:"Generic / Analog"}),"\n",(0,o.jsx)(n.p,{children:"The Analog output port is a 6-pin connector capable of delivering either 12V or 24V, depending on the connected power source. This port is inactive if the board is powered solely via USB-C."}),"\n",(0,o.jsxs)(n.ul,{children:["\n",(0,o.jsx)(n.li,{children:"Port Type: 6-pin"}),"\n",(0,o.jsx)(n.li,{children:"Voltage: 12V or 24V only. Powering using USB-C will not work."}),"\n",(0,o.jsx)(n.li,{children:"Usage: Designed for RGB CCT LED strips but can be repurposed for other devices due to PWM control or on/off switching capabilities"}),"\n",(0,o.jsx)(n.li,{children:"Pin Layout: Printed on the bottom side of the PCB"}),"\n"]}),"\n",(0,o.jsx)(n.admonition,{type:"danger",children:(0,o.jsx)(n.p,{children:"Never use USB-C and DC at the same time. Only one power source at a time is supported. Otherwise you will damage the PCB!"})}),"\n",(0,o.jsx)(n.hr,{}),"\n",(0,o.jsx)(n.h2,{id:"gpio",children:"GPIO"}),"\n",(0,o.jsx)(n.p,{children:"The PCB includes a range of GPIO pins, enabling you to expand the board's functionality with additional features or extension boards.\r\nThe GPIO pin layout is as follows (viewed from the top):"}),"\n",(0,o.jsx)(n.p,{children:"| 3.3V   | EN | TX | RX    | IO 0  | IO 33 | Ground | 5V            |\r\n| Ground | VP | VN | IO 34 | IO 35 | IO 32 | Ground | VCC (12V/24V) |"}),"\n",(0,o.jsx)(n.p,{children:"This table is also printed on the bottom of the PCB."}),"\n",(0,o.jsx)(n.p,{children:(0,o.jsx)(n.img,{src:t(3660).A+"",width:"1085",height:"500"})}),"\n",(0,o.jsx)(n.admonition,{type:"note",children:(0,o.jsxs)(n.ul,{children:["\n",(0,o.jsx)(n.li,{children:"Ensure proper voltage compatibility when connecting devices."}),"\n",(0,o.jsx)(n.li,{children:"Refer to the PCB's printed labels for accurate connections."}),"\n"]})})]})}function h(e={}){const{wrapper:n}={...(0,r.R)(),...e.components};return n?(0,o.jsx)(n,{...e,children:(0,o.jsx)(l,{...e})}):l(e)}},3660:(e,n,t)=>{t.d(n,{A:()=>i});const i=t.p+"assets/images/gpio pins-cfa19b4b0557b4c53c4d06abfd3f47fe.png"},8453:(e,n,t)=>{t.d(n,{R:()=>s,x:()=>a});var i=t(6540);const o={},r=i.createContext(o);function s(e){const n=i.useContext(r);return i.useMemo((function(){return"function"==typeof e?e(n):{...n,...e}}),[n,e])}function a(e){let n;return n=e.disableParentContext?"function"==typeof e.components?e.components(o):e.components||o:s(e.components),i.createElement(r.Provider,{value:n},e.children)}}}]);