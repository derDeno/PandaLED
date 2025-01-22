import {themes as prismThemes} from 'prism-react-renderer';
import * as OpenApiPlugin from "docusaurus-plugin-openapi-docs";

/** @type {import('@docusaurus/types').Config} */
const config = {
  title: 'PandaLED Docs',
  tagline: '',
  favicon: 'img/favicon.ico',

  url: 'https://derdeno.github.io',
  baseUrl: '/PandaLED/',
  organizationName: 'derDeno',
  projectName: 'PandaLED',

  onBrokenLinks: 'throw',
  onBrokenMarkdownLinks: 'warn',

  i18n: {
    defaultLocale: 'en',
    locales: ['en'],
  },

  presets: [
    [
      'classic',
      /** @type {import('@docusaurus/preset-classic').Options} */
      ({
        docs: {
          routeBasePath: '/',
          sidebarPath: './sidebars.js',
          showLastUpdateTime: true,
          docItemComponent: "@theme/ApiItem",
        },
        blog: false,
        theme: {
          customCss: './src/css/custom.css',
        },
      }),
    ],
  ],

  themeConfig:
    /** @type {import('@docusaurus/preset-classic').ThemeConfig} */
    ({
      image: 'img/social-card.jpg',
      colorMode: {
        defaultMode: 'light',
        disableSwitch: false,
        respectPrefersColorScheme: true,
      },
      navbar: {
        title: 'PandaLED',
        logo: {
          alt: 'PandaLED Logo',
          src: 'icon.svg',
          srcDark: 'icon-dark.svg',
        },
        items: [
          {
            type: 'docSidebar',
            sidebarId: 'docs',
            position: 'left',
            label: 'Docs',
          },
          {
            type: 'docSidebar',
            sidebarId: 'guides',
            position: 'left',
            label: 'Guides',
          },
          {
            href: 'https://derdeno.github.io/PandaLED/web-installer.html',
            label: 'Web Installer',
            position: 'left',
          },
          {
            href: 'https://github.com/derDeno/PandaLED',
            position: 'right',
            className: 'header-github-link',
            'aria-label': 'GitHub repository',
          },
        ],
      },
      footer: {
        style: 'dark',
        links: [],
        copyright: `Copyright © ${new Date().getFullYear()} PandaLED. Distributed by a <a href="https://github.com/derDeno/PandaLED/tree/main/LICENSE">CC BY-NC-SA 4.0 license.</a>`,
      },
      prism: {
        theme: prismThemes.github,
        darkTheme: prismThemes.dracula,
      },
    }),

  plugins: [
    require.resolve('docusaurus-lunr-search'),
    [
      'docusaurus-plugin-openapi-docs',
      {
        id: "api",
        docsPluginId: "classic",
        config: {
          petstore: {
            specPath: "examples/petstore.yaml",
            outputDir: "docs/petstore",
            sidebarOptions: {
              groupPathsBy: "tag",
            },
          },
        }
      },
    ]
  ],

  themes: ["docusaurus-theme-openapi-docs"],
};

export default config;
