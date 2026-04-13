// @ts-check
// `@type` JSDoc annotations allow editor autocompletion and type checking
// (when paired with `@ts-check`).
// There are various equivalent ways to declare your Docusaurus config.
// See: https://docusaurus.io/docs/api/docusaurus-config

import {themes as prismThemes} from 'prism-react-renderer';

// This runs in Node.js - Don't use client-side code here (browser APIs, JSX...)

/** @type {import('@docusaurus/types').Config} */
const config = {
  title: 'YSUSE Docs | 燕山大学软件工程专业不登校指南',
  tagline: 'Software Engineering is COOL',
  favicon: 'img/nina.png',

  // Set the production url of your site here
  url: 'https://rurumuri.github.io',
  // Set the /<baseUrl>/ pathname under which your site is served
  // For GitHub pages deployment, it is often '/<projectName>/'
  baseUrl: '/ysuse-2022/',

  // GitHub pages deployment config.
  // If you aren't using GitHub pages, you don't need these.
  organizationName: 'rurumuri', // Usually your GitHub org/user name.
  projectName: 'ysuse-2022', // Usually your repo name.

  onBrokenLinks: 'warn',
  onBrokenMarkdownLinks: 'warn',
  trailingSlash: false, // 消除 trailing slash 重定向，减少 Algolia crawler 的 Ignored 记录

  // SEO: Use headTags for structured data (JSON-LD). Metadata moved to themeConfig to satisfy TS types.
  headTags: [
    // JSON-LD structured data for better rich results in search engines
    {
      tagName: 'script',
      attributes: {
        type: 'application/ld+json',
      },
      innerHTML: JSON.stringify({
        '@context': 'https://schema.org',
        '@type': 'WebSite',
        name: 'YSUSE Docs',
        url: 'https://rurumuri.github.io/ysuse-2022/',
        description:
          '燕山大学软件工程专业不登校自学指南。',
        publisher: {
          '@type': 'Organization',
          name: 'rurumuri',
          url: 'https://github.com/rurumuri/ysuse-2022',
          logo: 'https://rurumuri.github.io/ysuse-2022/img/nina.png',
        },
        potentialAction: {
          '@type': 'SearchAction',
          target: {
            '@type': 'EntryPoint',
            urlTemplate:
              'https://rurumuri.github.io/ysuse-2022/search?q={search_term_string}',
          },
          'query-input': 'required name=search_term_string',
        },
      }),
    },
  ],

  // Even if you don't use internationalization, you can use this field to set
  // useful metadata like html lang. For example, if your site is Chinese, you
  // may want to replace "en" with "zh-Hans".
  i18n: {
    defaultLocale: 'zh-Hans',
    locales: ['zh-Hans'],
  },

  presets: [
    [
      'classic',
      /** @type {import('@docusaurus/preset-classic').Options} */
      ({
        docs: {
          sidebarPath: './sidebars.js',
          // Please change this to your repo.
          // Remove this to remove the "edit this page" links.
          editUrl:
            'https://github.com/rurumuri/ysuse-2022/tree/master',
          showLastUpdateAuthor: true,
          showLastUpdateTime: true,
        },
        // blog: {
        //   showReadingTime: true,
        //   feedOptions: {
        //     type: ['rss', 'atom'],
        //     xslt: true,
        //   },
        //   // Please change this to your repo.
        //   // Remove this to remove the "edit this page" links.
        //   editUrl:
        //     'https://github.com/rurumuri/ysuse-2022/tree/master',
        //   // Useful options to enforce blogging best practices
        //   onInlineTags: 'warn',
        //   onInlineAuthors: 'warn',
        //   onUntruncatedBlogPosts: 'warn',
        // },
        theme: {
          customCss: './src/css/custom.css',
        },
      }),
    ],
  ],

  themeConfig:
    /** @type {import('@docusaurus/preset-classic').ThemeConfig} */
    ({
      // SEO: social card (ideally 1200x630px for optimal sharing) and metadata for better SEO, OG
      image: 'img/nina.png',
      metadata: [
        {
          name: 'description',
          content:
            '燕山大学软件工程专业不登校指南，包含燕山大学信息科学与工程学院软件工程专业相关资料。目前资料和信息均以 2022 级课程为基础，部分内容可能具有时效性。',
        },
        {
          name: 'keywords',
          content:
            '燕山大学,软件工程,YSUSE,不登校指南,课程攻略,操作系统,数据结构,编译原理,计算机网络,数据库,软件工程,项目管理,机器学习,课程资料,自学指南',
        },
        {
          name: 'og:title',
          content: 'YSUSE Docs | 燕山大学软件工程专业不登校指南',
        },
        {
          name: 'og:description',
          content:
            '燕山大学软件工程专业不登校自学指南',
        },
        {
          name: 'og:type',
          content: 'website',
        },
      ],
      navbar: {
        title: 'YSUSE Docs',
        logo: {
          alt: '不登校',
          src: 'img/nina.png',
        },
        items: [
          {
            type: 'docSidebar',
            sidebarId: 'tutorialSidebar',
            position: 'left',
            label: 'Docs',
          },
          {
            href: 'https://github.com/rurumuri/ysuse-2022',
            label: 'GitHub',
            position: 'right',
          },
        ],
      },
      footer: {
        style: 'dark',
        links: [
          // {
          //   title: 'Docs',
          //   items: [
          //     {
          //       label: 'Tutorial',
          //       to: '/docs/intro',
          //     },
          //   ],
          // },
          // {
          //   title: 'Community',
          //   items: [
          //     {
          //       label: 'Stack Overflow',
          //       href: 'https://stackoverflow.com/questions/tagged/docusaurus',
          //     },
          //     {
          //       label: 'Discord',
          //       href: 'https://discordapp.com/invite/docusaurus',
          //     },
          //     {
          //       label: 'X',
          //       href: 'https://x.com/docusaurus',
          //     },
          //   ],
          // },
          // {
          //   title: 'More',
          //   items: [
          //     {
          //       label: 'GitHub',
          //       href: 'https://github.com/facebook/docusaurus',
          //     },
          //   ],
          // },
        ],
        copyright: `Copyright © ${new Date().getFullYear()} YSUSE Docs. Built with Docusaurus.`,
      },
      prism: {
        theme: prismThemes.github,
        darkTheme: prismThemes.dracula,
      },
      algolia: {

        // The application ID provided by Algolia
        appId: '1I69A1V27U',
  
        // Public API key: it is safe to commit it
        apiKey: 'aedb2d6f3d1383a15b30371f6fa4f192',
  
        indexName: 'rurumuriio',
  
        // Optional: see doc section below
        contextualSearch: true,
  
        // Optional: Specify domains where the navigation should occur through window.location instead on history.push. Useful when our Algolia config crawls multiple documentation sites and we want to navigate with window.location.href to them.
        // externalUrlRegex: 'external\\.com|domain\\.com',
  
        // Fix search result URLs for baseUrl /ysuse-2022/ and reduce redirect issues
        replaceSearchResultPathname: {
          from: '/ysuse-2022/docs/',
          to: '/docs/',
        },

        // Optional: Algolia search parameters for better Chinese docs relevance
        searchParameters: {
          facetFilters: ['language:zh-Hans', 'type:lvl0:Docs'],
        },
  
        // Optional: path for search page that enabled by default (`false` to disable it)
        searchPagePath: 'search',
  
        // Optional: whether the insights feature is enabled or not on Docsearch (`false` by default)
        insights: true,
  
        //... other Algolia params
      },
    }),
};

export default config;
